import torch 
from torch import nn

X1 = torch.tensor([[10]], dtype=torch.float32)
X2 = torch.tensor([[37.78]], dtype=torch.float32)

y1 = torch.tensor([[50]], dtype=torch.float32)
y2 = torch.tensor([[100]], dtype=torch.float32)

# Model
model = nn.Linear(1, 1)
loss_fn = nn.MSELoss()
optimizer = torch.optim.SGD(model.parameters(), lr=0.0001)

print(model.weight)

# Training
for i in range(0, 50000):
    optimizer.zero_grad()
    outputs = model(X1)
    loss = loss_fn(outputs, y1)
    loss.backward()
    optimizer.step()
    # 2
    optimizer.zero_grad()
    outputs = model(X2)
    loss = loss_fn(outputs, y2)
    loss.backward()
    optimizer.step()
    if i % 100 == 0:
        print(model.weight)
        print(model.bias)

# Prediction
y1_pred = model(X1)
print(f"Predictions is : {y1_pred}")



