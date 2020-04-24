# -*- coding: utf-8 -*-

from queue import PriorityQueue  # 默认从小到大
from heapq import heappush, heappop  # 默认从小到大


class Node:
    def __init__(self, x):
        self.val = x


if __name__ == '__main__':
    # ######################## PriorityQueue, int
    # l = [1, 3, 10, 5, 4, 15, 7]
    # que = PriorityQueue()
    # for v in l:
    #     que.put(v)
    # while(not que.empty()):
    #     v = que.get()
    #     print(v)

    # ######################## heapq, int
    # l = [1, 3, 10, 5, 4, 15, 7]
    # que = []
    # for v in l:
    #     heappush(que, v)
    # while(que):
    #     v = heappop(que)
    #     print(v)

    # ######################## PriorityQueue, Node
    # l = [Node(v) for v in [1, 3, 10, 5, 4, 15, 7]]
    # que = PriorityQueue()
    # for node in l:
    #     que.put((-node.val, node))
    # while(not que.empty()):
    #     v, node = que.get()
    #     print(v, node.val)

    # ######################## PriorityQueue, Node
    l = [Node(v) for v in [1, 3, 10, 5, 4, 15, 7]]
    que = []
    for node in l:
        heappush(que, (-node.val, node))
    while que:
        v, node = heappop(que)
        print(v, node.val)


