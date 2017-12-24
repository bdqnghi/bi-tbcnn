def knapsack_with_repetitions(weight_limit, value_list):
    """
        knapsack problem when items can be picked multiple times
        
    :param weight_limit: total weight of the knapsack 
    :param value_list: items with their weight and value
    :return: total value of the items filled in knapsack
    """

    value_sum = [0] * (weight_limit + 1)

    # base case
    value_sum[0] = 0

    for w in range(1, weight_limit + 1):
        for w_i in value_list.keys():
            if w_i <= w:
                cur = value_sum[w - w_i] + value_list[w_i]
                value_sum[w] = max(value_sum[w], cur)

    return value_sum[weight_limit]


def knapsack_without_repetitions(weight_limit, value_list, weight_list):
    """
        knapsack problem when items can NOT be picked multiple times

    :param weight_limit: total weight of the knapsack 
    :param value_list: items with their value
    :param weight_list: items with their weight
    :return: total value of the items filled in knapsack
    """

    n = len(value_list)
    value_sum_per_item = [[0] * (n + 1) for i in range(weight_limit + 1)]

    # base case
    for i in range(weight_limit + 1):
        value_sum_per_item[i][0] = 0

    for j in range(n + 1):
        value_sum_per_item[0][j] = 0

    # build table in bottom-up manner
    for j in range(1, n + 1):
        for w in range(1, weight_limit + 1):
            if weight_list[j - 1] > w:
                value_sum_per_item[w][j] = value_sum_per_item[w][j - 1]
            else:
                cur = value_sum_per_item[w - weight_list[j - 1]][j - 1] + value_list[j - 1]
                value_sum_per_item[w][j] = max(cur, value_sum_per_item[w][j - 1])

    return value_sum_per_item[weight_limit][n]


if __name__ == '__main__':

    weight_limit = 10
    value_list = {6: 30, 3: 14, 4: 16, 2: 9}

    print(knapsack_with_repetitions(weight_limit, value_list))

    weight_list = [6, 3, 4, 2]
    value_list = [30, 14, 16, 9]
    print(knapsack_without_repetitions(weight_limit, value_list, weight_list))
