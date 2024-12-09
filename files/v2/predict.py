import os

def thetas_create(file_path):
    """
    Create the thetas file passed as parameter if it doesn't exist
    Return zero thetas as a tuple (theta0, theta1) or (None, None) if an error occurred
    """
    try:
        if not os.path.exists(file_path):
            with open(file_path, 'w') as file:
                file.write("0\n0\n")
    except Exception as e:
        print(f"An error occurred while creating file '{file_path}'\n\t -> {e}")
        return (None, None)
    return (0, 0)


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


def mileage_load():
    """
    Load the mileage from the user input
    Return the mileage as a float or -1 if an error occurred
    """
    try:
        mileage = float(input("Enter the mileage of the car: "))
        if mileage < 0:
            raise ValueError("Mileage must be positive")
    except Exception as e:
        print(f"An error occurred while loading the mileage\n\t -> {e}")
        return (None)
    return (mileage)


def price_predict(theta0, theta1, mileage):
    """
    Predict the price of the car
    Return the price as an int
    """
    try:
        if mileage < 0:
            raise ValueError("Invalid input data")
        price = int(theta0 + theta1 * mileage)
    except Exception as e:
        print(f"An error occurred while predicting the price\n\t -> {e}")
        return (None)
    return (price)


def main():
    theta0, theta1 = thetas_create('.theta')
    if theta0 is None or theta1 is None:
        print("Thetas creation failed.")
        return

    theta0, theta1 = thetas_load('.theta')
    if theta0 is None or theta1 is None:
        print("Thetas loading failed.")
        return

    mileage = mileage_load()
    if mileage is None:
        print("Mileage loading failed.")
        return

    price = price_predict(theta0, theta1, mileage)
    if price is None:
        print("Price prediction failed.")
        return

    print(f"Estimated price             : {price}")


if __name__ == "__main__":
    main()
