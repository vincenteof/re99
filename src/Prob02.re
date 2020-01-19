/* Find the last but one element of a list. */

let rec butLast =
  fun
  | [] =>
    Js.Exn.raiseError(
      "The parameter list should contain at least two elements!",
    )
  | [_] =>
    Js.Exn.raiseError(
      "The parameter list should contain at least two elements!",
    )
  | [x, _] => x
  | [_, ...xs] => butLast(xs);

let butLastSafe = lst =>
  List.(
    lst |> fold_left(((_, b), x) => (b, Some(x)), (None, None)) |> fst
  );