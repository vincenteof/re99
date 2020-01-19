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

let rec myRange = (start, end_) =>
  if (start >= end_) {
    [];
  } else {
    [start, ...myRange(start + 1, end_)];
  };

let rec myZip = (lst1, lst2) =>
  switch (lst1, lst2) {
  | (_, []) => []
  | ([], _) => []
  | ([x, ...xs], [y, ...ys]) => [(x, y), ...myZip(xs, ys)]
  };

let kth2 = (lst, k) => {
  List.(
    if (k <= 0 || k > length(lst)) {
      Js.Exn.raiseError({j|Invalid index: $k|j});
    } else {
      k + 1 |> myRange(1) |> myZip(lst) |> rev |> hd |> fst;
    }
  );
};