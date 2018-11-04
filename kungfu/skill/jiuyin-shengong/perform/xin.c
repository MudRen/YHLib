#include <ansi.h>
#include <combat.h>

#define XIN "��" HIR "���Ĵ�" NOR "��"

inherit F_SSERVER;

void remove_effs(object target);

string final(object me, object target, int damage);

int perform(object me, object target)
{
        string msg;
        int ap, dp, damage;
        int times;

        me = this_player();

        if (userp(me) && ! me->query("can_perform/jiuyin-shengong/xin"))
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(XIN "ֻ����ս���жԶ���ʹ�á�\n");

        if ((int)me->query_skill("jiuyin-shengong", 1) < 280)
                return notify_fail("������񹦲�����죬����ʩչ" XIN "��\n");
 
        if ((int)me->query_skill("force", 1) < 280)
                return notify_fail("���ڹ���������������ʩչ" XIN "��\n");   

        if (me->query_skill_mapped("force") != "jiuyin-shengong")
                return notify_fail("��û�м���������Ϊ�ڹ�������ʩչ" XIN "��\n");

        if ((int)me->query("neili") < 500)
                return notify_fail("�����ڵ���������������ʩչ" XIN "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");
                            
        msg = HIM "\n$N" HIM "��Ȼ���Хһ����ʩչ���������еġ�" HIR "���Ĵ�" HIM"����"
              "ֻ��$N" HIM "������ʽǧ��ٹ֡��仯��ˣ�����ϲŭ���֣���״�ٳ���\n" NOR;

        ap = me->query_skill("jiuyin-shengong", 1) + me->query_skill("force", 1);
        dp = target->query_skill("martial-cognize", 1) + target->query_skill("force", 1);

        if (ap * 11 / 20 + random(ap) > dp)
        {
             msg += HIG "$n" HIG "��ʱ�����ؿڿ���֮���������������ƣ�ϲŭ���־�ȫ����$N" HIG
                    "���䡣���֮�䣬$n" HIG "�پ��������ã�ͷ��Ŀѣ��\n" NOR; 

             me->start_busy(2 + random(4));
             me->add("neili", -400);
             target->start_busy(2 + random(4));
             target->receive_damage("jing", ap / 2 + random(ap / 4) );
             target->receive_wound("jing", ap / 2 + random(ap / 8) );
             target->set_temp("eff/jiuyin-shengong/xin", 1);

             if (target->query_skill("martial-cognize", 1) < 200)times =  ap / 10 + random(6);
             if (target->query_skill("martial-cognize", 1) >= 200)times = ap / 11 + random(6);
             if (target->query_skill("martial-cognize", 1) >= 220)times = ap / 12 + random(6);
             if (target->query_skill("martial-cognize", 1) >= 260)times = ap / 14 + random(6);
             if (target->query_skill("martial-cognize", 1) >= 300)times = ap / 16 + random(6);
             if (target->query_skill("martial-cognize", 1) >= 340)times = ap / 18 + random(6);
             if (target->query_skill("martial-cognize", 1) >= 360)times = ap / 22 + random(6);
             if (target->query_skill("martial-cognize", 1) >= 380)times = ap / 30 + random(6);
             if (target->query_skill("martial-cognize", 1) > 400)times = 8 + random(7);
             remove_call_out("remove_effs");
             call_out("remove_effs", times, target); 	

        } else
        {
              msg += NOR + CYN "$n" NOR + CYN "ŭ�ȵ��������������������Ի��ң�������Ȼ�䣬��ʽ���죬"
                     "����$N" NOR + CYN "������ȥ��\n" NOR;
              me->add("neili", -200);
              me->start_busy(1 + random(2));
        }
        message_sort(msg, me, target);

        return 1;
}

void remove_effs(object target)
{
        if (! objectp(target) || ! target->query_temp("eff/jiuyin-shengong/xin"))return;
        target->delete_temp("eff/jiuyin-shengong/xin");
        tell_object(target, HIW "��Ȼ������Ѫ�ϳ壬ͷ����ʹ֮�ж�Ȼ��ȥ�������𽥼���������\n" NOR);
        return;      
}