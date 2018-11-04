// mail.c

#include <ansi.h>

inherit F_CLEAN_UP;

int help(object me);

void create() { seteuid(getuid()); }

int help(object me);
private void get_mail_to(string mailto, object me, string topic);
private void get_mail_subject(string topic, object me, string mailto);

int main(object me, string arg)
{
        string mailto, topic;

        if (! arg || sscanf(arg, "%s %s", mailto, topic) != 2)
        {
                mailto = arg;
                topic = 0;
        }

        if (! mailto || mailto == "")
        {
                write("�������㷢���ʼ��ĵ�ַ��");
                input_to("get_mail_to", me, 0);
                return 1;
        }

        get_mail_to(mailto, me, topic);
	return 1;
}

private void get_mail_to(string mailto, object me, string topic)
{
        string user, addr;

        if (! mailto || mailto == "" || sscanf(mailto, "%s@%s", user, addr) != 2 ||
            user == "" || addr == "")
        {
                tell_object(me, "��ָ���ķ��͵�ַ��ʽ����ȷ��\n");
                return;
        }

        if (topic)
        {
                get_mail_subject(topic, me, mailto);
                return;
        }

        write("���������ż��ı��⣺");
        input_to("get_mail_subject", me, mailto);
}

private void get_mail_subject(string topic, object me, string mailto)
{
        if (! topic || topic == "")
                topic = "û��";

        write(sprintf(WHT "�����ˣ�" CYN "%s  "
                      WHT "�����ˣ�" CYN "%s  "
                      WHT "���⣺" CYN "%s\n" NOR,
                      me->query("email"), mailto, topic));
        write("���������ż������ݡ�\n");
        me->edit(bind((: call_other, __FILE__, "done", me, mailto, topic :), me));
}

void done(object me, string mailto, string topic, string msg)
{
        if (! me || ! msg || msg == "")
                return;

        if (! wizardp(me) && time() - me->query_temp("last_mail") < 30)
        {
                tell_object(me, "������ʮ������ֻ�ܷ���һ���ż���\n");
                return;
        }

        me->set_temp("last_mail", time());
        if (! MAIL_D->queue_mail(me, me->query("email"),
                                 mailto, topic, msg))
        {
                tell_object(me, query_fail_msg());
                tell_object(me, "�����ʼ�ʧ�ܡ�\n");
        } else
                tell_object(me, "����ʼ��Ѿ�����<" + mailto + ">�ˡ�\n");
}

int help(object me)
{
	write(@HELP
ָ���ʽ�� mail [<��ַ>] [<����>]

���ָ�����㷢�Ÿ�ĳ�ˡ�
HELP );
	return 1;
}
