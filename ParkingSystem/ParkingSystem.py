
from typing import List, Optional
import collections


class ParkingSystem:

    def __init__(self, big: int, medium: int, small: int):
        self.park = [0, big, medium, small]

    def addCar(self, carType: int) -> bool:
        if self.park[carType] > 0:
                self.park[carType] -= 1
                return True
        return False
        






