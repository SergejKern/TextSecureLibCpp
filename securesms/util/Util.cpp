#include "Util.h"

//  static Handler handler = new Handler(Looper.getMainLooper());
//  static String join(Collection<String> list, String delimiter)
//  {
//    StringBuilder result = new StringBuilder();
//    int i = 0;
//
//    for (String item : list) {
//      result.append(item);
//
//      if (++i < list.size())
//        result.append(delimiter);
//    }
//
//    return result.toString();
//  }
//  static String join(long[] list, String delimeter)
//  {
//    StringBuilder sb = new StringBuilder();
//
//    for (int j=0;j<list.length;j++) {
//      if (j != 0) sb.append(delimeter);
//      sb.append(list[j]);
//    }
//
//    return sb.toString();
//  }
//  static ExecutorService newSingleThreadedLifoExecutor()
//  {
//    ThreadPoolExecutor executor = new ThreadPoolExecutor(1, 1, 0L, TimeUnit.MILLISECONDS, new LinkedBlockingLifoQueue<Runnable>());
//
//    executor.execute(new Runnable() {
//      @Override
//      public void run() {
////        Process.setThreadPriority(Process.THREAD_PRIORITY_BACKGROUND);
//        Thread.currentThread().setPriority(Thread.MIN_PRIORITY);
//      }
//    });
//
//    return executor;
//  }
//  static boolean isEmpty(EncodedStringValue[] value) {
//    return value == null || value.length == 0;
//  }
//
//  static boolean isEmpty(EditText value) {
//    return value == null || value.getText() == null || TextUtils.isEmpty(value.getText().toString());
//  }
//
//  static CharSequence getBoldedString(String value) {
//    SpannableString spanned = new SpannableString(value);
//    spanned.setSpan(new StyleSpan(Typeface.BOLD), 0,
//                    spanned.length(),
//                    Spannable.SPAN_EXCLUSIVE_EXCLUSIVE);
//
//    return spanned;
//  }
//
//  static @NonNull String toIsoString(byte[] bytes) {
//    try {
//      return new String(bytes, CharacterSets.MIMENAME_ISO_8859_1);
//    } catch (UnsupportedEncodingException e) {
//      throw new AssertionError("ISO_8859_1 must be supported!");
//    }
//  }
//
//  static byte[] toIsoBytes(String isoString) {
//    try {
//      return isoString.getBytes(CharacterSets.MIMENAME_ISO_8859_1);
//    } catch (UnsupportedEncodingException e) {
//      throw new AssertionError("ISO_8859_1 must be supported!");
//    }
//  }
//
//  static byte[] toUtf8Bytes(String utf8String) {
//    try {
//      return utf8String.getBytes(CharacterSets.MIMENAME_UTF_8);
//    } catch (UnsupportedEncodingException e) {
//      throw new AssertionError("UTF_8 must be supported!");
//    }
//  }
//
//  public static void wait(Object lock, long timeout) {
//    try {
//      lock.wait(timeout);
//    } catch (InterruptedException ie) {
//      throw new AssertionError(ie);
//    }
//  }
//
//  public static String canonicalizeNumber(Context context, String number)
//      throws InvalidNumberException
//  {
//    String localNumber = TextSecurePreferences.getLocalNumber(context);
//    return PhoneNumberFormatter.formatNumber(number, localNumber);
//  }
//
//  public static String canonicalizeNumberOrGroup(Context context, String number)
//      throws InvalidNumberException
//  {
//    if (GroupUtil.isEncodedGroup(number)) return number;
//    else                                  return canonicalizeNumber(context, number);
//  }
//
//  public static byte[] readFully(InputStream in) throws IOException {
//    ByteArrayOutputStream bout = new ByteArrayOutputStream();
//    byte[] buffer              = new byte[4096];
//    int read;
//
//    while ((read = in.read(buffer)) != -1) {
//      bout.write(buffer, 0, read);
//    }
//
//    in.close();
//
//    return bout.toByteArray();
//  }
//
//  public static String readFullyAsString(InputStream in) throws IOException {
//    return new String(readFully(in));
//  }
//
//  public static long copy(InputStream in, OutputStream out) throws IOException {
//    byte[] buffer = new byte[4096];
//    int read;
//    long total = 0;
//
//    while ((read = in.read(buffer)) != -1) {
//      out.write(buffer, 0, read);
//      total += read;
//    }
//
//    in.close();
//    out.close();
//
//    return total;
//  }
//
//  public static String getDeviceE164Number(Context context) {
//    String localNumber = ((TelephonyManager)context.getSystemService(Context.TELEPHONY_SERVICE))
//        .getLine1Number();
//
//    if (!TextUtils.isEmpty(localNumber) && !localNumber.startsWith("+"))
//    {
//      if (localNumber.length() == 10) localNumber = "+1" + localNumber;
//      else                            localNumber = "+"  + localNumber;
//
//      return localNumber;
//    }
//
//    return null;
//  }
//
//  public static <T> List<List<T>> partition(List<T> list, int partitionSize) {
//    List<List<T>> results = new LinkedList<>();
//
//    for (int index=0;index<list.size();index+=partitionSize) {
//      int subListSize = Math.min(partitionSize, list.size() - index);
//
//      results.add(list.subList(index, index + subListSize));
//    }
//
//    return results;
//  }
//
//  public static List<String> split(String source, String delimiter) {
//    List<String> results = new LinkedList<>();
//
//    if (TextUtils.isEmpty(source)) {
//      return results;
//    }
//
//    String[] elements = source.split(delimiter);
//    Collections.addAll(results, elements);
//
//    return results;
//  }
//
//  public static byte[][] split(byte[] input, int firstLength, int secondLength) {
//    byte[][] parts = new byte[2][];
//
//    parts[0] = new byte[firstLength];
//    System.arraycopy(input, 0, parts[0], 0, firstLength);
//
//    parts[1] = new byte[secondLength];
//    System.arraycopy(input, firstLength, parts[1], 0, secondLength);
//
//    return parts;
//  }
//
//  public static byte[] combine(byte[]... elements) {
//    try {
//      ByteArrayOutputStream baos = new ByteArrayOutputStream();
//
//      for (byte[] element : elements) {
//        baos.write(element);
//      }
//
//      return baos.toByteArray();
//    } catch (IOException e) {
//      throw new AssertionError(e);
//    }
//  }
//
//  public static byte[] trim(byte[] input, int length) {
//    byte[] result = new byte[length];
//    System.arraycopy(input, 0, result, 0, result.length);
//
//    return result;
//  }
//
//  @SuppressLint("NewApi")
//  public static boolean isDefaultSmsProvider(Context context){
//    return (Build.VERSION.SDK_INT < Build.VERSION_CODES.KITKAT) ||
//      (context.getPackageName().equals(Telephony.Sms.getDefaultSmsPackage(context)));
//  }
//
int Util::GetCurrentApkReleaseVersion(OsIndependentContext* context)
{
  //try
  //{
  return context->GetPackageManager()->GetPackageInfo(context->GetPackageName(), 0)->versionCode;
  //}
  //catch (PackageManager::NameNotFoundException e)
  //{
  //  throw new AssertionError(e);
  //}
}
//
//  public static String getSecret(int size) {
//    byte[] secret = getSecretBytes(size);
//    return Base64.encodeBytes(secret);
//  }
//
//  public static byte[] getSecretBytes(int size) {
//    byte[] secret = new byte[size];
//    getSecureRandom().nextBytes(secret);
//    return secret;
//  }
//
//  public static SecureRandom getSecureRandom() {
//    try {
//      return SecureRandom.getInstance("SHA1PRNG");
//    } catch (NoSuchAlgorithmException e) {
//      throw new AssertionError(e);
//    }
//  }
//
//  public static boolean isBuildFresh() {
//    return BuildConfig.BUILD_TIMESTAMP + TimeUnit.DAYS.toMillis(90) > System.currentTimeMillis();
//  }
//
//  @TargetApi(VERSION_CODES.LOLLIPOP)
//  public static boolean isMmsCapable(Context context) {
//    return (VERSION.SDK_INT >= VERSION_CODES.LOLLIPOP) || OutgoingLegacyMmsConnection.isConnectionPossible(context);
//  }
//
//  public static boolean isMainThread() {
//    return Looper.myLooper() == Looper.getMainLooper();
//  }
//
//  public static void assertMainThread() {
//    if (!isMainThread()) {
//      throw new AssertionError("Main-thread assertion failed.");
//    }
//  }
//
//  public static void runOnMain(Runnable runnable) {
//    if (isMainThread()) runnable.run();
//    else                handler.post(runnable);
//  }
//
//  public static boolean equals(@Nullable Object a, @Nullable Object b) {
//    return a == b || (a != null && a.equals(b));
//  }
//
//  public static int hashCode(@Nullable Object... objects) {
//    return Arrays.hashCode(objects);
//  }
//
//  @TargetApi(VERSION_CODES.KITKAT)
//  public static boolean isLowMemory(Context context) {
//    ActivityManager activityManager = (ActivityManager) context.getSystemService(Context.ACTIVITY_SERVICE);
//
//    return (VERSION.SDK_INT >= VERSION_CODES.KITKAT && activityManager.isLowRamDevice()) ||
//           activityManager.getMemoryClass() <= 64;
//  }
//
//  public static int clamp(int value, int min, int max) {
//    return Math.min(Math.max(value, min), max);
//  }
//
//  public static float clamp(float value, float min, float max) {
//    return Math.min(Math.max(value, min), max);
//  }
};
