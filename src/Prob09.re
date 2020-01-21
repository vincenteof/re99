/* Pack consecutive duplicates of list elements into sublists. */

let pack = lst => {
  let packFunc = (cur, acc) => {
    switch (acc) {
    | [] => [[cur]]
    | [[], ..._] => Js.Exn.raiseError("There should be some sub empty list!")
    | [[x, ..._] as first, ...restAcc] =>
      if (cur == x) {
        [[cur, ...first], ...restAcc];
      } else {
        [[cur], ...acc];
      }
    };
  };
  List.(fold_right(packFunc, lst, []));
};