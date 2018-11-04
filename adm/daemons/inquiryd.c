#include <ansi.h>

int parse_inquiry(object me, object ob, string topic)
{
	switch (topic)
        {
	case "name":
		message_vision(CYN "$N" CYN "��$n" CYN "�ʵ�������" +
                               RANK_D->query_respect(ob) + "���մ�"
                               "����\n" NOR, me, ob);
		return 1;

	case "here":
		message_vision(CYN "$N" CYN "��$n" CYN "�ʵ�����λ" +
                               RANK_D->query_respect(ob) + "��" +
                               RANK_D->query_self(me) + "�����󱦵�"
                               "����֪������Щʲ��������飿\n" NOR,
                               me, ob);
		return 1;

	case "clue":
	case "����":
		message_vision(CYN "$N" CYN "��$n" CYN "��������" +
                               RANK_D->query_self(me) + "�����˴���"
                               "֪" + RANK_D->query_respect(ob) +
                               "��Щ�������ܷ��֪���£�\n" NOR, me, ob);
		return 1;

	case "rumor":
	case "rumors":
        case "��Ϣ":
		message_vision(CYN "$N" CYN "��$n" CYN "�ʵ�����λ" +
			       RANK_D->query_respect(ob) + "����֪"
                               "�����û����˵ʲô��Ϣ��\n" NOR, me,
                               ob);
		return 1;

	default:
		return 0;
	}
}
