open Jest;
open Prob09;

describe("Prob09.compress", () => {
  open Expect;
  test("handles the case of empty list", () =>
    expect(pack([])) |> toEqual([])
  );
  test("handles the case of list with many elements", () =>
    expect((
      pack(["a"]),
      pack(["a", "a"]),
      pack(["a", "a", "a"]),
      pack(["a", "b", "b", "a", "a", "b", "b"]),
      pack([
        "a",
        "a",
        "a",
        "a",
        "b",
        "c",
        "c",
        "a",
        "a",
        "d",
        "e",
        "e",
        "e",
        "e",
      ]),
    ))
    |> toEqual((
         [["a"]],
         [["a", "a"]],
         [["a", "a", "a"]],
         [["a"], ["b", "b"], ["a", "a"], ["b", "b"]],
         [
           ["a", "a", "a", "a"],
           ["b"],
           ["c", "c"],
           ["a", "a"],
           ["d"],
           ["e", "e", "e", "e"],
         ],
       ))
  );
});