/*
  Eliminate consecutive duplicates of list elements.
  If a list contains repeated elements they should be replaced with a single copy of the element.
  The order of the elements should not be changed.
 */

let compress = lst => {
  let rec compress_recur = (origin, result) => {
    switch (origin, result) {
    | ([], _) => result
    | ([x, ...xs], []) => compress_recur(xs, [x])
    | ([x, ...xs], [y, ..._]) =>
      if (x == y) {
        compress_recur(xs, result);
      } else {
        compress_recur(xs, [x, ...result]);
      }
    };
  };

  [] |> compress_recur(lst) |> List.rev;
};

let rec compressSimple =
  fun
  | [] => []
  | [x] => [x]
  | [x, y, ...rest] => {
      let restWithY = [y, ...rest];
      if (x == y) {
        compressSimple(restWithY);
      } else {
        [x, ...compressSimple(restWithY)];
      };
    };