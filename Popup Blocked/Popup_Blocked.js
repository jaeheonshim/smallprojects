function unblockPopups() {
  var spamopen = 1;
  var window0 = window.open("https://www.google.com");
  var window1 = window.open("https://www.google.com");

  if (!window1 || window1.closed || typeof window1.closed == 'undefined') {
    window0.close();
    return true;
  }
  else {
    window0.close();
    window1.close();
    return false;
  }
}