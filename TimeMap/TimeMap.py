
from typing import List
import collections


class TimeMap:

    def __init__(self):
        self.my_map = {}


    def set(self, key: str, value: str, timestamp: int) -> None:
        if key not in self.my_map:
            self.my_map[key] = []
        self.my_map[key].append((value, timestamp))


    def get(self, key: str, timestamp: int) -> str:
        res, my_list = "", self.my_map.get(key, [])
        
        l, r = 0, len(my_list) - 1

        while l <= r:
            m = (l + r) // 2
            if my_list[m][1] <= timestamp:
                res = my_list[m][0]
                l = m + 1
            else:
                r = m - 1
        
        return res
            






timeMap = TimeMap()
timeMap.set("foo", "bar", 1)         # store the key "foo" and value "bar" along with timestamp = 1.
print(timeMap.get("foo", 1))         # return "bar"
print(timeMap.get("foo", 3))         # return "bar", since there is no value corresponding to foo at timestamp 3 and timestamp 2, then the only value is at timestamp 1 is "bar".
timeMap.set("foo", "bar2", 4)        # store the key "foo" and value "bar2" along with timestamp = 4.
print(timeMap.get("foo", 4))         # return "bar2"
print(timeMap.get("foo", 5))         # return "bar2"


