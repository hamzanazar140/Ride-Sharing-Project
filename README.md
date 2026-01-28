# Ride Sharing System – Design Document

## 1. Zone and Slot Representation

In this project, the city is simplified and divided logically rather than using a real map or graph.

- **Zone Representation**:
  - The system assumes a single logical zone.
  - All drivers and riders belong to the same zone.
  - This keeps the design beginner-friendly while maintaining clarity.

- **Slot Representation**:
  - Each driver represents a **slot**.
  - A driver slot can be in one of two states:
    - Available
    - Busy
  - Slots are stored using a fixed-size array of Driver objects.

This approach avoids complex data structures while clearly modeling availability.

---

## 2. Allocation Strategy

The allocation strategy is **first-available assignment**.

Steps:
1. When a rider requests a ride, the system scans the driver array.
2. The first driver marked as `available = true` is selected.
3. That driver is assigned to the ride.
4. The driver is marked as unavailable.

If no driver is available, the request is rejected.

This strategy is:
- Simple
- Deterministic
- Easy to implement without STL or advanced data structures

---

## 3. Request Lifecycle State Machine

Each ride follows a strict lifecycle controlled using an enum-based state machine.

### Ride States:
- `ASSIGNED`
- `COMPLETED`
- `CANCELLED`

### Valid Transitions:
- ASSIGNED → COMPLETED
- ASSIGNED → CANCELLED

### Invalid Transitions:
- COMPLETED → ASSIGNED
- CANCELLED → ASSIGNED

State transitions are enforced in the system to prevent invalid behavior.

This ensures:
- Data consistency
- Correct driver availability handling
- Clear ride history tracking

---

## 4. Rollback Design

The rollback mechanism is implemented in a simplified manner.

- When a ride is **cancelled**:
  - The ride state is changed to `CANCELLED`
  - The assigned driver is restored to `available = true`
- This effectively rolls back the driver assignment operation.

The system does not store a full operation stack but ensures:
- Driver availability is always restored correctly
- System state remains consistent after cancellation

This design demonstrates rollback concepts without using stacks or STL containers.

---

## 5. Time and Space Complexity

### Time Complexity:
- Driver allocation: **O(n)**  
  (linear scan of driver array)
- Ride completion/cancellation: **O(n)**  
  (searching rides and drivers)

### Space Complexity:
- Drivers array: **O(D)**
- Riders array: **O(R)**
- Rides array: **O(T)**

Where:
- D = number of drivers
- R = number of riders
- T = number of rides

All data is stored in fixed-size arrays, ensuring predictable memory usage.

---

## Conclusion

This project demonstrates:
- Modular design using header and source files
- Basic state machine implementation
- Safe driver allocation and rollback handling
- Clear time and space complexity analysis

The design prioritizes simplicity, correctness, and adherence to project constraints.
