import math

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


def model_precision(mileage, price, theta0, theta1):
    """
    Calculate the precision of the model
    Return the precision with MAPE as a float or None if an error occurred
    """
    try:
        mae = 0
        for i in range(len(mileage)):
            price_predict = theta0 + theta1 * mileage[i]
            mae += abs(price[i] - price_predict)
        mae /= len(mileage)
        print(f"MAE  : {mae:.2f} (price difference)")

        mse = 0
        for i in range(len(mileage)):
            price_predict = theta0 + theta1 * mileage[i]
            mse += (price[i] - price_predict) ** 2
        mse /= len(mileage)
        print(f"MSE  : {mse:.2f} (squared price difference)")

        mape = 0
        for i in range(len(mileage)):
            price_predict = theta0 + theta1 * mileage[i]
            if price[i] != 0:
                mape += abs(price[i] - price_predict) / price[i]
        mape /= len(mileage)
        mape *= 100
        print(f"MAPE : {mape:.2f} %")

        smape = 0
        for i in range(len(mileage)):
            price_predict = theta0 + theta1 * mileage[i]
            denominator = (abs(price[i]) + abs(price_predict)) / 2
            if denominator != 0:
                smape += abs(price[i] - price_predict) / denominator
        smape /= len(mileage)
        smape *= 100
        print(f"SMAPE: {smape:.2f} %")

        msle = 0
        for i in range(len(mileage)):
            price_predict = theta0 + theta1 * mileage[i]
            msle += (math.log(price[i] + 1) - math.log(price_predict + 1)) ** 2
        msle /= len(mileage)
        print(f"MSLE : {msle:.2f} (squared log-transformed price difference)")

        rmsle = 0
        for i in range(len(mileage)):
            price_predict = theta0 + theta1 * mileage[i]
            rmsle += (math.log(price[i] + 1) - math.log(price_predict + 1)) ** 2
        rmsle /= len(mileage)
        rmsle = math.sqrt(rmsle)
        print(f"RMSLE: {rmsle:.2f} (root squared log-transformed price difference)")

    except Exception as e:
        print(f"An error occurred while calculating the precision\n\t -> {e}")
        return (None)
    return (mape)


def main():
    mileage, price = data_load('../../datasets/data.csv')
    if mileage is None or price is None:
        print(f"Data loading failed.")
        return

    theta0, theta1 = thetas_load('.theta')
    if theta0 is None or theta1 is None:
        print("Thetas loading failed.")
        return

    precision = model_precision(mileage, price, theta0, theta1)
    if precision is None:
        print("Precision calculation failed.")
        return


if __name__ == "__main__":
    main()