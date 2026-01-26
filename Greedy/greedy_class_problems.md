# 🧠 Greedy Ideas — Problem References

This document contains **carefully selected problems** corresponding to the greedy techniques discussed in class.  
Each problem includes a **collapsible hint** so you can try it yourself before peeking 👀

Some problems are **exact matches**, and some are **closely related variants** using the same greedy patterns.

---

## 📌 Q1 — Minimum Scalar Product (Rearrangement Inequality)

🔗 **Problem Link:**  
https://open.kattis.com/problems/minimumscalar

📝 **Match with class:** ✅ Exact

<details>
<summary>💡 Click to reveal hint</summary>

Sort one array in **ascending** order and the other in **descending** order.  
This is an application of the **rearrangement inequality** and can be proven using a **swap argument**.

</details>

---

## 📌 Q2 — CSES — Task Scheduling / Projects

🔗 **Problem Link:**  
https://cses.fi/problemset/task/1630/

📝 **Match with class:** ⚠️ Similar (not exact)

<details>
<summary>💡 Click to reveal hint</summary>

Think in terms of **ordering the tasks** to minimize total penalty / loss.  
Try comparing two tasks `i` and `j` and decide which should come first using a **swap argument**.

You will end up sorting by a **ratio or cross-multiplication condition**.

</details>

---

## 📌 Q3 — Stone Game VI (Alice & Bob Greedy Game)

🔗 **Problem Link:**  
https://leetcode.com/problems/stone-game-vi/description/

📝 **Match with class:** ✅ Exact

<details>
<summary>💡 Click to reveal hint</summary>

When it's a player's turn, they should pick the stone that **maximizes (Ai + Bi)**.  
This reduces the game to **sorting by (Ai + Bi)** and picking alternately.

</details>

---

## 📌 Q4 — Codeforces 520B — Two Buttons (Operation Decode / Reverse Greedy)

🔗 **Problem Link:**  
https://codeforces.com/problemset/problem/520/B

📝 **Match with class:** ✅ Exact

<details>
<summary>💡 Click to reveal hint</summary>

Work **backwards** from `B` to `A`:
- If `B` is even → divide by 2  
- If `B` is odd → add 1  

When `B ≤ A`, just add `(A - B)` to the answer.

</details>

---

## 📌 Q5 — Gas Station (Fuel / Cost Optimization)

🔗 **Problem Link:**  
https://leetcode.com/problems/gas-station/description/

📝 **Match with class:** ⚠️ Similar (not exact)

<details>
<summary>💡 Click to reveal hint</summary>

Try to think in terms of **feasibility** instead of simulation.  
Track **total gas vs total cost** and find a **valid starting point** using greedy prefix logic.

(This is different from the priority-queue fuel-cost problem, but conceptually related.)

</details>

---

## 🏁 Summary

| Question | Topic | Match with Class |
|----------|--------|------------------|
| Q1 | Minimum Dot Product | ✅ Exact |
| Q2 | Greedy Scheduling | ⚠️ Similar |
| Q3 | Alice & Bob Game | ✅ Exact |
| Q4 | Reverse Greedy Operations | ✅ Exact |
| Q5 | Fuel / Traversal Greedy | ⚠️ Similar |

---

