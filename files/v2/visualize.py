import matplotlib.pyplot as plt

def data_load(file_path):
    """
    Load the data from the file
    Return the mileage and price as a tuple (mileage, price) or (None, None) if an error occurred
    """
    try:
        mileage = []
        price = []
        with open(file_path, 'r') as file:
            for line in file:
                stripped_line = line.strip()
                if stripped_line:
                    parts = stripped_line.split(',')
                    if len(parts) != 2:
                        raise ValueError("Invalid data format")
                    if parts[0] == "km" and parts[1] == "price":
                        continue
                    else:
                        mileage.append(float(parts[0]))
                        price.append(float(parts[1]))
    except Exception as e:
        print(f"An error occurred while loading file '{file_path}'\n\t -> {e}")
        return (None, None)

    return (mileage, price)


def thetas_load(file_path):
    """
    Load the thetas from the file passed as parameter
    Return thetas as a tuple (theta0, theta1) or (-1, -1) if an error occurred
    """
    try:
        with open(file_path, 'r') as file:
            line0 = file.readline().strip()
            theta0 = float(line0) if line0 else 0
            line1 = file.readline().strip()
            theta1 = float(line1) if line1 else 0
    except Exception as e:
        print(f"An error occurred while loading file '{file_path}'\n\t -> {e}")
        return (None, None)
    return (theta0, theta1)

def result_visualize(mileage, price, theta0, theta1):
    """
    Visualize the result of the prediction
    """
    plt.scatter(mileage, price, color='blue')
    plt.plot([0, max(mileage)], [theta0, theta0 + theta1 * max(mileage)], color='red')
    plt.xlabel('Mileage')
    plt.ylabel('Price')
    plt.title('Car Price Prediction - Regression Line')
    plt.legend(['Data', 'Regression Line'])
    plt.show()

    average_slope = sum((mileage[i] - sum(mileage) / len(mileage)) * (price[i] - sum(price) / len(price)) for i in range(len(mileage))) / sum((mileage[i] - sum(mileage) / len(mileage)) ** 2 for i in range(len(mileage)))
    intercept = sum(price) / len(price) - average_slope * (sum(mileage) / len(mileage))

    plt.scatter(mileage, price, color='red')
    plt.plot([0, max(mileage)], [intercept + average_slope * min(mileage), intercept + average_slope * max(mileage)], color='blue')
    plt.xlabel('Mileage')
    plt.ylabel('Price')
    plt.title('Car Price - Average Slope')
    plt.legend(['Data', 'Average Slope'])
    plt.show()

def main():
    mileage, price = data_load('../../datasets/data.csv')
    if mileage is None or price is None:
        print(f"Data loading failed.")
        return

    theta0, theta1 = thetas_load('.theta')
    if theta0 is None or theta1 is None:
        print("Thetas loading failed.")
        return

    result_visualize(mileage, price, theta0, theta1)

    print(f"Visualization done.")

if __name__ == "__main__":
    main()
