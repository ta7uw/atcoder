def binary_search(items, target):
    lo = 0
    hi = len(items) - 1
    found = False

    while lo <= hi and not found:
        mid = (lo + hi) // 2
        if items[mid] == target:
            found = True

        else:
            if target < items[mid]:
                hi = mid - 1
            else:
                lo = mid + 1

    return found
