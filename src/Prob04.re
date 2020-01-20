/* Find the number of elements of a list */

let rec len =
  fun
  | [] => 0
  | [_, ...xs] => len(xs) + 1;

let lenUsingFold = lst => {
  open List;
  let lenFunc = (acc, _) => acc + 1;
  fold_left(lenFunc, 0, lst);
};