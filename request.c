// count fields in message
int fields = 0;
haystack = needle + 2;
while (*haystack != '\0')
{
    // look for CRLF
    needle = strstr(haystack, "\r\n");
    if (needle == NULL)
    {
        break;
    }

    // ensure field is no longer than LimitRequestFieldSize
    if (needle - haystack + 2 > LimitRequestFieldSize)
    {
        break;
    }

    // look beyond CRLF
    haystack = needle + 2;
}

// if we didn't get to end of message, we must have erred
if (*haystack != '\0')
{
    break;
}

// ensure message has no more than LimitRequestFields
if (fields > LimitRequestFields)
{
	break;
}
