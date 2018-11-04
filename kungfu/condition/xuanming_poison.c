#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;
inherit POISON;

string name() { return "xuanming_poison"; }

string chinese_name() { return "��ڤ����"; }

string update_msg_others()
{
       return HIW "$N��ɫ���ϣ�ȫ��ס�Ĳ��������ظ�����졣\n" NOR;
}

string update_msg_self()
{
        return HIW "ֻ�е�һ���溮��������Ȼ����������������������������ڤ����֮�������ˣ�\n" NOR;
}

int jing_damage(object me, mapping cnd)
{
        return cnd["level"] / 6;
}

int qi_damage(object me, mapping cnd)
{
        return cnd["level"] / 5;
}

int dispel(object me, object ob, mapping cnd)
{

        if ((me->query_skill("jiuyang-shengong", 1) > 180 && 
             me->query_skill_mapped("force") == "jiuyang-shengong") ||
             (me->query_skill("xuanming-shengong", 1) > 180 &&
              me->query_skill_mapped("force") == "xuanming-shengong"))
        {               
                            
               me->add_temp("apply/dispel-poison", 1000);
               me->set_temp("add_dispel", 1);               
               call_out("clear_dispel", 2, me);
        }

        return ::dispel(me, ob, cnd);


}

void clear_dispel(object me)
{
       if (me->query_temp("apply/dispel-poison") && 
           me->query_temp("add_dispel"))
       {
                me->delete_temp("add_dispel");
                me->add_temp("apply/dispel-poison", -1000);
                return;
       }
               
}