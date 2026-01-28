# 📌 AtCoder ABC221 D — Online Games

🔗 **Problem Link:**  
https://atcoder.jp/contests/abc221/tasks/abc221_d

---

## 🧠 Hint (spoiler-protected)

<details>
<summary>💡 Click to reveal hint</summary>

This is a classic **sweep line / difference array** problem.

Treat each player’s interval as:
- `+1` at day `A_i`
- `-1` at day `A_i + B_i`

Collect all event days, sort them, and sweep in increasing order.  
Between two consecutive event days `x` and `y`, the number of active players is constant, so you can add `(y - x)` to `ans[active]`.

</details>
