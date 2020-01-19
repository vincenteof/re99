/* Find the K'th element of a list. The first element in the list is number 1. */

let rec kth = (lst, k) => {
  open List;
  let lstLen = length(lst);
  if (k <= 0 || k > lstLen) {
    Js.Exn.raiseError({j|Invalid index: $k|j});
  } else {
    switch (k) {
    | 1 => hd(lst)
    | _ => kth(tl(lst), k - 1)
    };
  };
};