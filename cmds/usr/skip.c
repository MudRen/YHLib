// skip.c

#include <command.h>

inherit F_CLEAN_UP;

int help(object me);

int main(object me, string arg)
{
        mixed list;
        mixed info;
        string msg;

        list = me->query_temp("tell_list");
        if (arrayp(list) && sizeof(list) > 0)
        {
                if (arg == "all")
                {
                        // ��ʾ���е���ʷ��Ϣ
                        msg = "���������յ���������Ϣ��\n";
                        foreach (info in list)
                        {
                                if (! arrayp(info) || sizeof(info) < 3 ||
                                    ! stringp(info[2]))
                                        // ������ʷ��Ϣ���Ϸ�
                                        continue;
                                msg += info[2];
                        }
                        if (strlen(msg) < 1024)
                                tell_object(me, msg);
                        else
                                // ��Ϣ̫��
                                me->start_more(msg);

                        me->delete_temp("tell_list");
                        me->delete_temp("reply");
                        return 1;
                }

                // ȥ��һ����Ϣ
                list = list[1..<1];

                // ����һ�£�ȡ����һ����ʷ��Ϣ
                while (sizeof(list) > 0)
                {
                        info = list[0];
                        if (! arrayp(info) || sizeof(info) < 3 ||
                            ! stringp(info[0]) ||
                            ! stringp(info[1]) ||
                            ! stringp(info[2]))
                        {
                                // ������ʷ��Ϣ���Ϸ�
                                list = list[1..<1];
                                continue;
                        }

                        // �ҵ��˺Ϸ�����ʷ��Ϣ
                        me->set_temp("reply", info[1]);
                        if (strlen(info[2]) < 1024)
                                tell_object(me, info[2]);
                        else
                                // ��ʷ��Ϣ̫������Ҫ��MORE��ʽ��ʾ
                                me->start_more(info[2]);
                        break;
                }

                if (sizeof(list) < 1)
                {
                        // �Ѿ�û���κ���Ϣ��
                        me->delete_temp("tell_list");
                        me->delete_temp("reply");
                        if (previous_object() != find_object(REPLY_CMD))
                                write("����û���κ���ʷ��Ϣ�ˡ�\n");
                        return 1;
                } else
                        me->set_temp("tell_list", list);
        } else
        {
                if (! undefinedp(list))
                        me->delete_temp("tell_list");

                if (previous_object() != find_object(REPLY_CMD))
                        write("�����ڲ��յ�û���κ���Ϣ��\n");
        }

	return 1;
}

int help(object me)
{
	write(@HELP
ָ���ʽ��skip [all]

�����ͱ��˽�̸��ʱ��������������ʽ�Ľ�̸����ô����ش�ĳ��
��Ϣ֮ǰϵͳ���Ὣ�����κ���Ľ�̸��Ϣ���͸��㡣����㲻��Ҫ
�ش�ֱ���뿴�������Ϣ���Ϳ����� skip �����Թ�����skip all
�����������Ϣ����������õ��ǰ�������ʽ����ô��ʹ��ش�ĳ��
��Ϣ��ϵͳҲ����������һ����Ϣ�������ֹ�����skip���������
Ϣ������ʱ�������ʾ�� > ������ɫ��

������������� . �����档

see also : tell��reply
HELP );
	return 1;
}
