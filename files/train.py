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


def thetas_save(theta0, theta1, file_path):
    """
    Save the thetas to the file passed as parameter
    Return 0 if successful or None if an error occurred
    """
    try:
        with open(file_path, 'w') as file:
            file.write(f"{theta0}\n")
            file.write(f"{theta1}\n")
    except Exception as e:
        print(f"An error occurred while saving file '{file_path}'\n\t -> {e}")
        return (None)
    return (0)


def model_train(mileage, price, learning_rate, iteration_max, tolerance):
    """
    Train the model with the data passed as parameter
    Return the thetas as a tuple (theta0, theta1)
    """
    theta0 = 0
    theta1 = 0

    tmp0 = 0
    tmp1 = 0

    if len(mileage) != len(price) or len(mileage) == 0 or len(price) == 0 or learning_rate <= 0 or iteration_max <= 0 or tolerance < 0:
        return (None, None)

    mean_price = sum(price) / len(price)
    std_price = (sum((price[x] - mean_price) ** 2 for x in range(len(price))) / len(price)) ** 0.5
    scaled_price = [(price[x] - mean_price) / std_price for x in range(len(price))]

    mean_mileage = sum(mileage) / len(mileage)
    std_mileage = (sum((mileage[x] - mean_mileage) ** 2 for x in range(len(mileage))) / len(mileage)) ** 0.5
    scaled_mileage = [(mileage[x] - mean_mileage) / std_mileage for x in range(len(mileage))]

    print(f"Training started with {len(mileage)} samples...")
    for i in range(iteration_max):
        estimate_price = [theta0 + theta1 * scaled_mileage[x] for x in range(len(mileage))]

        tmp0 -= learning_rate * sum((estimate_price[x] - scaled_price[x]) for x in range(len(mileage))) / len(mileage)
        tmp1 -= learning_rate * sum((estimate_price[x] - scaled_price[x]) * scaled_mileage[x] for x in range(len(mileage))) / len(mileage)

        delta0 = abs(tmp0 - theta0)
        delta1 = abs(tmp1 - theta1)

        theta0 = tmp0
        theta1 = tmp1

        if delta0 < tolerance and delta1 < tolerance:
            break

    print(f"Training took {i+1} iterations")

    theta0 = theta0 * std_price + mean_price - theta1 * mean_mileage * std_price / std_mileage
    theta1 = theta1 * std_price / std_mileage

    return (theta0, theta1)


def main():
    mileage, price = data_load('../../datasets/data.csv')
    if mileage is None or price is None:
        print(f"Data loading failed.")
        return

    theta0, theta1 = model_train(mileage, price, float(1e-4), int(42e+7), float(1e-12))
    if theta0 is None or theta1 is None:
        print(f"Model training failed.")
        return

    success = thetas_save(theta0, theta1, '.theta')
    if success is None:
        print(f"Thetas saving failed.")
        return

    print(f"Training completed.")

if __name__ == "__main__":
    main()
