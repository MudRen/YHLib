#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;
inherit POISON;

string name() { return "sha_poison"; }

string chinese_name() { return "ɰ��"; }

string update_msg_others()
{
       return HIR "$N" HIR "��ɫ���ر��ɷ�ף�ȫ��ͣ�Ĳ�����\n" NOR;
}

string update_msg_self()
{
        return HIR "��ֻ���������ģ���ʱ�е�һ��Ī���Ķ��ģ�ȫ��̱��������\n" NOR;
}

