
#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;
inherit POISON;

string name() { return "hanbingdu"; }

string chinese_name() { return "��������綾"; }

string update_msg_others()
{
        return HIW "$N" HIW "��ɫ�԰ף���֫��Ӳ��ȫ������͸����"
               "������\n" NOR;
}

string update_msg_self()
{
        return HIW "��ֻ��ȫ������ޱȣ���֫�ٺ�����֮�������"
               "������\n" NOR;
}

