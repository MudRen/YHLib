#include <ansi.h>
#include <combat.h>

#include "/kungfu/skill/eff_msg.h";

inherit F_SSERVER;

#define TU "��" HIW "̫��ͼ" NOR "��"

int perform(object me)
{
        object *obs;
        string msg;
        int damage;
        int ap, dp;
        int flag;
        int i;
        int p;

        if (userp(me) && me->query("can_perform/taiji-quan/tu") < 10)
                return notify_fail("����ʹ�õ��⹦��û�����ֹ��ܡ�\n");

        me->clean_up_enemy();
        if (! me->is_fighting())
                return notify_fail(TU "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail(TU "ֻ�ܿ���ʩչ��\n");

        if ((int)me->query_skill("taiji-quan", 1) < 250)
                return notify_fail("���̫��ȭ������죬����ʩչ" TU "��\n");

        if ((int)me->query_skill("taiji-shengong", 1) < 300)
                return notify_fail("���̫������Ϊ�������ߣ�����ʩչ" TU "��\n");

        if ((int)me->query_skill("taoism", 1) < 300)
                return notify_fail("��ĵ�ѧ�ķ���Ϊ�������ߣ�����ʩչ" TU "��\n");

        if (me->query_skill_mapped("unarmed") != "taiji-quan")
                return notify_fail("������û�м���̫��ȭ������ʩչ" TU "��\n");

        if (me->query_skill_mapped("force") != "taiji-shengong")
                return notify_fail("������û�м���̫���񹦣�����ʩչ" TU "��\n");

        if (me->query_skill_prepared("unarmed") != "taiji-quan")
                return notify_fail("��û��׼��ʹ��̫��ȭ������ʩչ" TU "��\n");

        if ((int)me->query("jingli") < 1000)
                return notify_fail("�����ھ�������������ʩչ" TU "��\n");

        if ((int)me->query("neili", 1) < 1000)
                return notify_fail("��������������������ʩչ" TU "��\n");

        msg = HIM "$N" HIM "��ȻһЦ��˫�����Ữ������Ȧ�ӣ���ʱ���ܵ���"
              "��������ԴԴ���ϵı�ǣ��������\n\n" NOR;
        message_combatd(msg, me);

        me->add("neili", -1000);
        me->add("jingli", -1000);
        me->start_busy(4);
        ap = me->query_skill("taoism", 1) +
             me->query_skill("taiji-quan", 1) +
             me->query_skill("taiji-shengong", 1);
        obs = me->query_enemy();
        for (flag = 0, i = 0; i < sizeof(obs); i++)
        {
                dp = obs[i]->query_skill("force") * 2 +
                     obs[i]->query_skill("taoism", 1);
                if (ap / 2 + random(ap) > dp)
                {
                        switch (random(3))
                        {
                        case 0:
                                tell_object(obs[i], HIY "���֮�����ƺ��ص��˹�ȥ�����磬��"
                                                    "Ȼ���޷��������ң���Ȼ��ǰ��һ��\n"
                                                    "��ȫȻ����������ͷһ�ң�����һ���"
                                                    "ʹ�������������Կ��ƣ�\n" NOR);
                                break;
                        case 1:
                                tell_object(obs[i], HIW "����ǰһ�н�����ģ�������������ǵ�"
                                                    "���ɾ���Ȼ����ȴ������ϢԽ��Խ�ң�\n"
                                                    "��֫һ����ʹ������Ҫվ����ס��\n" NOR);
                                break;
                        default:
                                tell_object(obs[i], HIR "����ߺ�Ȼ����һ���������ۼ������"
                                                    "��紸����������㲻�����һ����\n"
                                                    "�������¶�����ʹ����ֻ�и������ȡ�\n" NOR);
                                break;
                        }
                        damage = ap / 3 + random(ap / 3);

                        obs[i]->receive_damage("qi", damage, me);
                        obs[i]->receive_wound("qi", damage / 2, me);

                        obs[i]->receive_damage("jing", damage / 3, me);
                        obs[i]->receive_wound("jing", damage / 6, me);

                        p = (int)obs[i]->query("qi") * 100 / (int)obs[i]->query("max_qi");

                        switch (random(3))
                        {
                        case 0:
                                msg = HIR "ֻ��" + obs[i]->name() +
                                      HIR "�����㵸���������ԣ���"
                                      "Ȼ���һ������Ѫ��ֹ��\n" NOR;
                                msg += "( " + obs[i]->name() + eff_status_msg(p) + " )\n\n";
                                break;
                        case 1:
                                msg = HIR "ȴ��" + obs[i]->name() +
                                      HIR "��ò���ݣ��ƺ�������ʲ"
                                      "ô����֮�£�����һ�Σ�Ż��������Ѫ��\n" NOR;
                                msg += "( " + obs[i]->name() + eff_status_msg(p) + " )\n\n";
                                break;
                        default:
                                msg = HIR + obs[i]->name() +
                                      HIR "����������һ��������������"
                                      "а�����϶��ų���Ѫ����\n" NOR;
                                msg += "( " + obs[i]->name() + eff_status_msg(p) + " )\n\n";
                                break;
                        }
                        obs[i]->start_busy(3);
                        message("vision", msg, environment(me), ({ obs[i] }));
                        obs[i]->add("neili", -500);
                        flag = 1;
                } else
                {
                        tell_object(obs[i], HIC "�㷢����ǰ�ľ����ƻ����棬��æ"
                                            "Ĭ���ڹ����������š�\n" NOR);
                        obs[i]->add("neili", -200);
                }
                if (obs[i]->query("neili") < 0)
                        obs[i]->set("neili", 0);
        }

        if (! flag) 
                message_vision(HIM "Ȼ��û���κ�������$N"
			       HIM "��Ӱ�졣\n\n" NOR, me, 0, obs);

        return 1;
}
