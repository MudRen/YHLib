// version.c

#include <getconfig.h>

inherit F_CLEAN_UP;

void show_version();

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
        int ver;

        if (arg == "stop" || arg == "cancel")
        {
                if (! SECURITY_D->valid_grant(me, "(admin)"))
                        return 0;

                if (VERSION_D->clear_syn_info())
                        write("����˰汾�������ڵ�ͬ����Ϣ��\n");
                else
                        write("Ŀǰ�汾����û���κ�ͬ����Ϣ��\n");

                return 1;
        }

        if (arg == "sync" || arg == "SYNC")
        {
        	if (! SECURITY_D->valid_grant(me, "(arch)"))
                {
        		write("��û��Ȩ��ͬ��" + LOCAL_MUD_NAME() +
                              "�İ汾��\n");
                        return 1;
                }

                if (arg == "sync" &&
                    intp(ver = VERSION_D->query("version")) &&
                    time() > ver && time() - ver < 86400)
                {
                        write("����汾�����һ�����ɵģ�������û�б�Ҫ��ͬ����\n");
                        return 1;
                }

                return VERSION_D->synchronize_version();
        }

        if (arg && sscanf(arg, "get %s", arg))
        {
        	if (! SECURITY_D->valid_grant(me, "(admin)"))
                {
        		write("��û��Ȩ�޶�ȡ�������ϵ��ļ���\n");
                        return 1;
                }

                return VERSION_D->fetch_file(arg);
        }

        show_version();

	return 1;
}

void show_version()
{
        int ver;

        if (! VERSION_D->is_version_ok())
        {
                write("Ŀǰ�汾����ͬ���С�\n");
                return;
        }

        if (! intp(ver = VERSION_D->query("version")) || ! ver)
        {
                write(sprintf("%sĿǰ���еİ汾���顣\n",
                              LOCAL_MUD_NAME()));
                return;
        }

	write(sprintf("%sĿǰ���еİ汾�ǣ�%O[%s ����]\n",
                      LOCAL_MUD_NAME(), ver, ctime(ver)));
}

int help(object me)
{
        write(@HELP
ָ���ʽ : version [sync] | get <file>
 
���ָ�����ʾ��ϷĿǰ���õ� MudLib �汾�����ָ����sync������
��ϵͳ������ͬ�����µİ汾��ע�⣺��������ͬ���ǲ��ɿ��ģ���
Ϊϵͳ�����Զ��ĸ����Ѿ������ڴ�Ķ���ֻ�е������ڴ��еĶ�
������Ժ󣬰汾��������ͬ���ˡ����ͬ����汾�������������
MUD �����ֹ�����(update)��Щ��ͬ�ĵط���

ʹ�� version get <file> ���Զ�ȡ�������� /version/  ·������
��ĳ���ļ���
 
HELP );
    return 1;
}
