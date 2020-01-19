/* Find the last element of a list. */

let rec last1 = lst =>
  switch (lst) {
  | [] => Js.Exn.raiseError("The parameter should not be empty!")
  | [x] => x
  | [_, ...xs] => last1(xs)
  };

let last2 = lst => lst |> List.rev |> List.hd;