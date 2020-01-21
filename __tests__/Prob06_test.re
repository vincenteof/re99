open Jest;
open Prob06;

describe("Prob06.isPalindrome", () => {
  open Expect;
  test("handles the case of empty list", () =>
    expect(isPalindrome([])) |> toEqual(true)
  );
  test("handles the case of list with element(s)", () =>
    expect((
      isPalindrome([1]),
      isPalindrome([1, 2, 1]),
      isPalindrome([1, 1]),
      isPalindrome([1, 2, 3, 4]),
      isPalindrome(["a", "b", "c", "d", "e"]),
    ))
    |> toEqual((true, true, true, false, false))
  );
});