#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;
inherit POISON;

string name() { return "tiezhang_yin"; }

string chinese_name() { return "����������"; }

string update_msg_others()
{
        return HIB "$N" HIB "��ɫ�Ұף���Ƥ���ϣ��䲻������һ����ս��\n" NOR;
}

string update_msg_self()
{
        return HIB "��е��ؿڴ����������ʹ��ȫ��ѪҺ����Ҫ����סһ�㡣\n" NOR;
}

