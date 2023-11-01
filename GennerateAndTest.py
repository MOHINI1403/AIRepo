import itertools
def generate_and_test(target_sum, num_dice):
    def generate_dice_rolls(num_dice):
        # Generate all possible dice rolls for a single die
        return [[i + 1 for i in range(6)] for _ in range(num_dice)]

    def test_combination(combination, target_sum):
        # Test if the sum of the dice rolls equals the target sum
        return sum(combination) == target_sum

    # Generate all possible dice rolls
    dice_rolls = generate_dice_rolls(num_dice)

    # Generate and test combinations
    solutions = [combination for combination in itertools.product(*dice_rolls) if test_combination(combination, target_sum)]

    return solutions


target_sum = 7
num_dice = 2

solutions = generate_and_test(target_sum, num_dice)
print(f"Combinations of {num_dice} dice rolls that sum up to {target_sum}:")
print(solutions)