// clear.c

inherit F_CLEAN_UP;

int help(object me);

int main(object me, string arg)
{
        string target;
	object obj;

        if (! SECURITY_D->valid_grant(me, "(admin)"))
                return 0;

	seteuid(getuid(me));

	if (! arg) return notify_fail("ָ���ʽ : clear [-u] <���֮��"
                                      "�ƻ���> | <���ID> <����>\n" );

        if (sscanf(arg, "-u %s", arg) == 1)
        {
		if (sscanf(arg, "%s %s", target, arg) != 2)
		{
			write("�����ָ������û���ʲô���ݡ�\n");
			return 1;
		}

                // clear the user data
                write ("����û�(" + target + ")�����ݣ�" +
                       UPDATE_D->clear_user_data(target, arg));
                return 1;
        }

        if (arg == "-u")
        {
                help(me);
                return 1;
        }

        target = arg;
	obj = find_object(target);
        if ((! obj  || userp(obj)) && file_size(target + ".c") >0 )
                catch(obj = load_object(target));
	if (! obj || userp(obj)) obj = present(target, me);
	if (! obj || userp(obj)) obj = present(target, environment(me));
	if (! obj || userp(obj)) obj = find_object(resolve_path(me->query("cwd"), target));
	if (! obj || userp(obj)) catch(obj = load_object( resolve_path(me->query("cwd"), target)));
	if (obj && ! userp(obj))
        {
	        message_vision(sprintf("$N�����<%O>��ͬ���̼�¼һ��"
                                       "���׵Ĵݻ��ˡ�\n", obj), me);
	        if (! DBASE_D->clear_object(obj))
                        write ("��û���ܹ��ɹ��Ĵݻ�����ͼ�¼��\n");
	        else
                        write("Ok.\n");
        } else
        {
                write("����ͼ�����ݿ��������Ŀ(" + target + ")�ļ�¼��\n");
	        if (! DBASE_D->clear_object(target))
                        write ("��û���ܹ��ɹ��������¼��\n");
	        else
                        write("Ok.\n");
        }

	return 1;
}

int help(object me)
{
	write(@HELP
ָ���ʽ : clear [-u] <���֮���ƻ���> | <���ID> <����>

���ô�һָ��ɽ�һ�����(object)��ͬ���Ĵ��̼�¼һ�������ע
�⣺����Ĵ��̼�¼ָ�������ݱ����� DBASE_D �е���Щ���� ��
����¼�Ǳ���ɵ������ļ��������ǵĴ��̼�¼�����ܵ��κ�Ӱ�죬
����������ṩ����ʦ���ܵ����˵Ķ�����������޸�ʱʹ�õġ�

���ʹ�ò��� -u�����ʾ��Ҫ���һ����Ҷ� MUD �еĶ������ݣ�
����˵ס������Ϣ�Ϳ���ͨ�����������������ָ������ҵ�ס����
�١�

���������all      ��������
          board    ���԰�
          couple   ����
          item     ����
          name     ����
          room     ����
          brothers ����
          league   ����
          title    �ƺ�

�ο����ϣ� dest��query
HELP );
    return 1;
}
