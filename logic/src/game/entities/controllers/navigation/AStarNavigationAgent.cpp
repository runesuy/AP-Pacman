//
// Created by runes on 9/12/2025.
//

#include "game/entities/controllers/navigation/AStarNavigationAgent.h"
#include <algorithm>
#include <utility>

namespace logic {
    Direction AStarNavigationAgent::getNavigationDirection(const Position &current, const Position &target,
                                                           const World &world,
                                                           std::set<Direction> excludeIfOtherOptions) const {
        struct Node {
            double f;
            double g;
            double h;
            Position position;
            // shared pointer can be used since start node has no parent (nullptr)
            std::shared_ptr<Node> parent;

            Node(double f, double g, double h, Position position, std::shared_ptr<Node> parent)
                : f(f), g(g), h(h), position(std::move(position)), parent(std::move(parent)) {
            }
        };
        // initialize lists
        std::vector<std::shared_ptr<Node> > openList;
        std::vector<std::shared_ptr<Node> > closedList;

        // push start node
        openList.push_back(std::make_shared<Node>(0, 0, 0, current, nullptr));

        bool found = false;
        std::shared_ptr<Node> goalNode = nullptr;
        while (!openList.empty() && !found) {
            // q = node with the lowest f in open list
            auto itQ = std::ranges::min_element(openList,
                                                [](const std::shared_ptr<Node> &a, const std::shared_ptr<Node> &b) {
                                                    return a->f < b->f;
                                                });
            const auto q = *itQ;

            // pop q from open list
            openList.erase(itQ);

            // get 4 successors of q
            std::vector<std::shared_ptr<Node> > successors;
            const double tileSize = world.getConfig().getTileMap().getTileSize();
            for (const Direction &dir: {Direction::UP, Direction::DOWN, Direction::LEFT, Direction::RIGHT}) {
                auto successor = std::make_shared<Node>(0, 0, 0, Position{0, 0}, q);
                // calculate position
                double newX=0;
                double newY=0;
                switch (dir) {
                    case Direction::UP:
                        newY = q->position.getY() + tileSize;
                        break;
                    case Direction::DOWN:
                        newY = q->position.getY() - tileSize;
                        break;
                    case Direction::LEFT:
                        newX = q->position.getX() - tileSize;
                        break;
                    case Direction::RIGHT:
                        newX = q->position.getX() + tileSize;
                        break;
                    default:
                        break;
                }
                if (std::abs(newX)>1 || std::abs(newY)>1) {
                    continue; // out of bounds
                }
                successor->position = {newX, newY};
                successors.push_back(successor);
            }

            for (const auto &successor: successors) {
                if (successor->position.isEqualTo(target, 0.01)) {
                    found = true;
                    goalNode = successor;
                    break;
                }

                // calculate g, h, f
                successor->g = q->g + 1;
                // Manhattan distance for h
                successor->h = std::abs(successor->position.getX() - target.getX()) +
                               std::abs(successor->position.getY() - target.getY());
                successor->f = successor->g + successor->h;

                // if a node with the same position as successor is in the OPEN list which has a lower f than successor, skip this successor
                auto itOpen = std::find_if(openList.begin(), openList.end(),
                                           [&successor](const std::shared_ptr<Node> &node) {
                                               return node->position.isEqualTo(successor->position, 0.01) && node->f <=
                                                      successor->f;
                                           });
                if (itOpen != openList.end()) continue;

                /* if a node with the same position as
                successor  is in the CLOSED list which has
                a lower f than successor, skip this successor
                otherwise, add  the node to the open list*/

                auto itClosed = std::find_if(closedList.begin(), closedList.end(),
                                             [&successor](const std::shared_ptr<Node> &node) {
                                                 return node->position.isEqualTo(successor->position, 0.01) && node->f
                                                        <= successor->f;
                                             });
                if (itClosed != closedList.end()) continue;
                openList.push_back(successor);
            }

            // push q to closed list
            closedList.push_back(q);
        }

        if (!found) return NONE;
        if (openList.empty()) return NONE;

        // give direction of first step in path
        // 2. Trace the Path Backwards
        std::vector<std::shared_ptr<Node> > path;
        std::shared_ptr<Node> currentPathNode = goalNode;

        // Traverse the parent pointers until we hit the start node (parent is null)
        while (currentPathNode) {
            path.push_back(currentPathNode);
            currentPathNode = currentPathNode->parent;
        }

        // 3. The Path is currently Goal -> ... -> Start. Reverse it to Start -> ... -> Goal
        std::reverse(path.begin(), path.end());

        // 4. Find the Second Node (The first step to take)
        // The path size must be at least 2 (Start and Goal). If only 1, it means Start == Goal.
        if (path.size() < 2) {
            // This case should ideally not happen if 'found' is true, unless current == target.
            if (current.isEqualTo(target, 0.01)) return Direction::NONE; // Already there
            return Direction::NONE;
        }

        const auto &startNode = path[0]; // This is `current`
        const auto &firstStepNode = path[1]; // This is the node we want to move toward

        return getDirectionTo(startNode->position, firstStepNode->position);
    }
} // logic
