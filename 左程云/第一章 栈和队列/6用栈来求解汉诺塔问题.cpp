/*
    汉诺塔问题比较经典，这里修改一下游戏规则：现在限制不能从最左侧的塔直接移动到最
右侧，也不能从最右侧直接移动到最左侧，而是必须经过中间。求当塔有 N 层的时候，打印最
优移动过程和最优移动总步数。
    例如，当塔数为两层时，最上层的塔记为 1，最下层的塔记为 2，则打印：
    Move 1 from left to mid
    Move 1 from mid to right
    Move 2 from left to mid
    Move 1 from right to mid
    Move 1 from mid to left
    Move 2 from mid to right
    Move 1 from left to mid
    Move 1 from mid to right
    It will move 8 steps.    
*/

