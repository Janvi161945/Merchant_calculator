def calculate_cost(quintal, rate, hamal_charge, weighage):
    total_cost = quintal * rate
    return total_cost

def calculate_hamal_charge(total_quintal):
    return total_quintal * 10.30

def calculate_weighage(total_quintal):
    return total_quintal * 7.0

def get_input(prompt):
    while True:
        try:
            value = float(input(prompt))
            return value
        except ValueError:
            print("Invalid input. Please enter a numeric value.")

# Get the number of kinds of goods
num_goods = int(input("Enter the number of kinds of goods: "))

# Initialize a list to store the costs for each kind of goods
total_costs = []
total_quintal = 0

# Get input and calculate total cost for each kind of goods
for i in range(num_goods):
    print(f"\n--- Goods {i+1} ---")
    quintal = get_input("Enter the quintal: ")
    rate = get_input("Enter the rate: ")
    total_quintal += quintal

    # Calculate total cost
    total_cost = calculate_cost(quintal, rate, 0, 0)
    total_costs.append(total_cost)

    # Perform calculation of quintal * rate
    calculation_result = quintal * rate

    # Print the results for each kind of goods
    # print("Calculation:", quintal, "*", rate, "=", calculation_result)
    print("Total cost:", total_cost)

# Calculate hamal_charge and weighage based on total quintal
hamal_charge = calculate_hamal_charge(total_quintal)
weighage = calculate_weighage(total_quintal)

# Subtract hamal_charge and weighage from the overall total cost
overall_total_cost = sum(total_costs)
overall_total_cost -= hamal_charge
overall_total_cost -= weighage

# Print the overall total cost along with hamal_charge and weighage
print("\nHamal Charge:", hamal_charge)
print("Weighage:", weighage)
print("Calculated Hamal Charge + Weighage:", hamal_charge + weighage)
print("Overall Total cost:", overall_total_cost)
