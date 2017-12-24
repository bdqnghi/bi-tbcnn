import random


def ZeroOneKnapsack(values, weights, capacity):
  assert len(values) == len(weights)
  results = {}
  return _ZeroOneKnapsack(values, weights, capacity, len(values), results)
  
  
def _ZeroOneKnapsack(values, weights, capacity, n, results):
  if capacity in results and n in results[capacity]:
    return results[capacity][n]
  
  if n == 0:
    result = [], 0., 0.
  else:
    # Without the last item.
    content_wo, value_wo, weight_wo = _ZeroOneKnapsack(
        values, weights, capacity, n-1, results)

    # With the last item.
    if weights[n-1] <= capacity:
      content_w, value_w, weight_w = _ZeroOneKnapsack(
          values, weights, capacity - weights[n-1], n-1, results)
      content_w += [n-1]
      value_w += values[n-1]
      weight_w += weights[n-1]
    else:
      value_w = -1.

    if value_w > value_wo:
      result = content_w, value_w, weight_w
    else:
      result = content_wo, value_wo, weight_wo

  results[capacity] = {n: result}
  return result


def ContinuousKnapsack(values, weights, capacity):
  """Expected O(n)."""
  assert len(values) == len(weights)
  return _ContinuousKnapsack(values, weights, capacity, 0, len(values))


def _ContinuousKnapsack(values, weights, capacity, start, end):
  # Base case.
  if capacity <= 0:
    return []
  if start >= end:
    return []

  # Recursion case.
  pivot = random.randint(start, end - 1)
  pivot, total_low_weight, total_high_weight = PartitionByDensity(
      values, weights, start, pivot, end)

  if total_high_weight > capacity:
    return _ContinuousKnapsack(values, weights, capacity, pivot + 1, end)
  else:
    # Add all of the high density.
    solution = [(i, weights[i]) for i in range(pivot + 1, end)]
    remaining_capacity = capacity - total_high_weight

    # Add as much the middle density as available.
    if remaining_capacity > 0:
      pivot_contributed_weight = min([remaining_capacity, weights[pivot]])
      solution += [(pivot, pivot_contributed_weight)]
      remaining_capacity -= pivot_contributed_weight

    # Add as much the low density as available.
    if remaining_capacity > 0:
      solution += _ContinuousKnapsack(
          values, weights, remaining_capacity, start, pivot)
    return solution
  

def PartitionByDensity(values, weights, start, pivot, end):
  pivot_density = Density(values, weights, pivot)
  Swap(values, weights, pivot, end - 1)

  low_weight, high_weight = 0., 0.
  low = high = start
  while high < end - 1:
    density = Density(values, weights, high)
    if density < pivot_density:
      low_weight += weights[high]
      Swap(values, weights, high, low)
      low += 1
    else:
      high_weight += weights[high]
    high += 1
  Swap(values, weights, low, end - 1)

  return low, low_weight, high_weight


def Swap(values, weights, i, j):
  temp_value = values[i]
  temp_weight = weights[i]
  values[i] = values[j]
  weights[i] = weights[j]
  values[j] = temp_value
  weights[j] = temp_weight


def Density(values, weights, i):
  return float(values[i]) / float(weights[i])


import unittest


class TestKnapsack(unittest.TestCase):

  def test_ZeroOne(self):
    values = [60, 100, 120]
    weights = [10, 20, 30]
    capacity = 50
    self.assertEqual(
        ([1, 2], 220.0, 50.0),
        ZeroOneKnapsack(values, weights, capacity))

  def test_Continuous(self):
    values = [60, 100, 120]
    weights = [10, 20, 30]
    capacity = 50
    self.assertEqual(
        [(0, 20.), (1, 20.), (2, 10.)],
        sorted(ContinuousKnapsack(values, weights, capacity)))
