/* Reverse a list */

let reverse = lst => {
  open List;
  let reverseFunc = (revLst, cur) => [cur, ...revLst];
  fold_left(reverseFunc, [], lst);
};