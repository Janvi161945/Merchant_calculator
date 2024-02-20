from flask import Flask, render_template, request

app = Flask(__name__)

def calculate_cost(quintal, rate):
    total_cost = quintal * rate
    return total_cost

def calculate_hamal_charge(total_quintal):
    return total_quintal * 10.30

def calculate_weighage(total_quintal):
    return total_quintal * 7.0

@app.route('/', methods=['GET', 'POST'])
def home():
    if request.method == 'POST':
        quintal = float(request.form['quintal'])
        rate = float(request.form['rate'])
        total_cost = calculate_cost(quintal, rate)
        total_quintal = quintal
        hamal_charge = calculate_hamal_charge(total_quintal)
        weighage = calculate_weighage(total_quintal)
        overall_total_cost = total_cost - hamal_charge - weighage
        return render_template('result.html', hamal_charge=hamal_charge, weighage=weighage, overall_total_cost=overall_total_cost)
    return render_template('index.html')

if __name__ == '__main__':
    app.run(debug=True)
