import torch

X = torch.tensor([[10.0], [37.78], [50], [100]], dtype=torch.float32)
y = torch.tensor([[50], [100], [112], [212]], dtype=torch.float32)

model = torch.nn.Linear(1, 1)
loss_fn = torch.nn.MSELoss()
optimiser = torch.optim.SGD(model.parameters(), lr=0.0001)

for i in range(0, 10000):
    optimiser.zero_grad()
    outputs = model(X)
    loss = loss_fn(outputs, y)
    loss.backward()
    optimiser.step()

    if i % 100 == 0:
        print(model.bias)
        print(model.weight)

print(f"predictions = {model(X)}")

test = torch.tensor([[31], [23], [-16]], dtype=torch.float32)
model.eval()
with torch.no_grad():
    print(f"predictions = {model(test)}")