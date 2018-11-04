inherit SKILL;

#include <ansi.h>
#include <combat.h>

string *parry_msg = ({
        "$Nһ�л���$n���ϣ�ȴ��$n����Ǭ����Ų�ƣ�����������������¡�\n",
        "$n����һ����$N�����Լ������ػ��������ŵ������˼�����\n",
        "$n�ֱۻ�ת����$N����������һ�ƣ�$N������ա�\n",
        "$n�����������$N����������һ����$N���Ʋ�ס��ֱ��ǰ��ȥ��\n",
        "$n���β�����$Nһ�л��£�����ʯ���󺣣�������ס�ˡ�\n",
        "$n��ǣ������$N��������������ת�˺ü���Ȧ�ӡ�\n",
        "$n˫�ֻ�Ȧ��$Nֻ����ǰ�������һ��ǽ����Ҳ������ȥ��\n",
        "$n����һת��$Nһ�л��ڵ��ϣ�ֻ��ó������\n",
});

string *pfail_msg = ({
        "$n����Ǭ����Ų�ƣ���ͼ����������������£�Ȼ��$N���ѿ������а�������仯Ī�⡣\n",
        "$n����һ����$N�����Լ������ػ���������æ���У���ת���⣬����$n����ʤ����\n",
        "$n�ֱۻ�ת����$N����������һ�ƣ�Ȼ��$N��������һ�䣬��δ��ա�\n",
        "$n�����������$N����������һ����$N���Ʋ�ס��˳�Ʊ�����ǰֱ����\n",
        "$n��ǣ������$N����������˳�Ʊ��У�Բת���⣬����������\n",
        "$n˫�ֻ�Ȧ��$Nֻ����ǰ�������һ��ǽ����Ȼ���ѣ�������һ�㣬�����Է���\n",
});

int valid_enable(string usage) 
{ 
        return usage == "parry";
}

string query_parry_msg(string limb)
{
        return parry_msg[random(sizeof(parry_msg))];
}

int valid_learn(object me)
{
        int layer;

        if (me->query("gender") == "����" &&
            me->query_skill("qiankun-danuoyi", 1) >= 50)
                return notify_fail("����ͼ�����ķ�������Ų�ƣ�ȴ"
                                   "��������һ����ã�����Լ�����\n");

        if (me->query_condition("qiankun-except"))
                return notify_fail("������������������֫�Ժ������"
                                   "����޷����������񹦡�\n");

        layer = (int)me->query_skill("qiankun-danuoyi", 1) / 50;
        if (layer > 7) layer = 7;

		if (me->query("int") < 36 )
                return notify_fail("�����Ǭ����Ų��ʵ��������ޱȣ�ȫȻ�޷���⡣\n");

        //if (me->query("int") < 32 + layer )
        //      return notify_fail("����õ�" + chinese_number(layer) +
        //                          "��Ǭ����Ų��ʵ��������ޱȣ�ȫȻ�޷���⡣\n");

		if (me->query("int") < 43 + layer - (int)me->query_skill("force")/50)
                return notify_fail("����õ�" + chinese_number(layer) +
                                   "��Ǭ����Ų��ʵ��������ޱȣ�ȫȻ�޷���⡣\n");

        if ((int)me->query("max_neili") < 6000)
                return notify_fail("���������Ϊ̫��޷�����Ǭ����Ų�ơ�\n");
        
        if ((int)me->query_skill("force") < 450)
                return notify_fail("����ڹ���򲻹����޷�����Ǭ����Ų�ơ�\n");

        if ((int)me->query_skill("parry", 1) < (int)me->query_skill("qiankun-danuoyi", 1))
                return notify_fail("��Ļ����мܻ�����ޣ��޷����������Ǭ����Ų�ơ�\n");

        if ((int)me->query_skill("dodge", 1) < (int)me->query_skill("qiankun-danuoyi", 1))
                return notify_fail("��Ļ����Ṧ������ޣ��޷����������Ǭ����Ų�ơ�\n");

        if ((int)me->query_skill("force", 1) < (int)me->query_skill("qiankun-danuoyi", 1))
                return notify_fail("��Ļ����ڹ�������ޣ��޷����������Ǭ����Ų�ơ�\n");

        return 1;
}

mixed valid_damage(object ob, object me, int damage, object weapon)
{
        mapping result;
        string msg;
        int ap, dp, mp, sk, ma, wn, na;

        sk = ob->query_skills();
        ma = ob->query_skill_map();

        if ((int)me->query_skill("qiankun-danuoyi", 1) < 100
           || ! living(me))
                return;

        mp = ob->query_skill("count", 1);
        ap = ob->query_skill("force", 1) + mp;
        dp = me->query_skill("parry", 1);

        if (ap / 2 + random(ap) < dp
           && ! me->is_busy()
           && ! me->query_temp("nuoyi")
           && ! ob->query_temp("nuoyi")
           && me->query_skill("qiankun-danuoyi", 1) > 350
           && me->query("max_neili") * 2 / 3 > ob->query("max_neili")
           && random(30) == 1
           && sizeof(sk)
           && sizeof(ma) != 0
           && mapp(ma)
           && mp < 100)
        {
                if (objectp(weapon = ob->query_temp("weapon")))
		{
			wn = weapon->query("skill_type");
			na = ob->query_skill_mapped(wn);
		} else

		if (ob->query_skill_prepared("finger"))
			na = ob->query_skill_mapped("finger");
		else

		if (ob->query_skill_prepared("strike"))
			na = ob->query_skill_mapped("strike");
		else

		if (ob->query_skill_prepared("claw"))
			na = ob->query_skill_mapped("claw");
		else

		if (ob->query_skill_prepared("cuff"))
			na = ob->query_skill_mapped("cuff");
		else

		if (ob->query_skill_prepared("hand"))
			na = ob->query_skill_mapped("hand");
		else
			na = ob->query_skill_mapped("unarmed");

                msg = HIM "\n$N" HIM "һ�й�����ȴ��$n" HIM "ӭ���"
                      "�ϣ���Ц����������" + CHINESE_D->chinese(na) +
                      HIM "�������ҺΣ���\n$n" HIM "��������Ǭ����Ų"
                      "�Ƶ��߲��ķ�����ͼŲ��$N" HIM "�Ĺ��ơ�\n\n" NOR;

                me->start_call_out((: call_other, __FILE__, "nuoyi",
                                      ob, me :), 1);
                me->set_temp("nuoyi/" + ob->query("id"), 1);
                me->start_busy(2);

                result = ([ "damage" : -damage,
                            "msg"    : msg ]);

                return result;
        } else

        if (ap / 2 + random(ap) < dp)
        {
                msg = parry_msg[random(sizeof(parry_msg))];
                msg = replace_string(msg, "$N", "$N" HIG);
                msg = replace_string(msg, "$n", "$n" HIG);
                msg = HIG + msg + NOR;

                result = ([ "damage": -damage,
                            "msg"   : msg ]);

                return result;
        } else

        if (mp >= 100)
        {
                msg = pfail_msg[random(sizeof(pfail_msg))];
                msg = replace_string(msg, "$N", "$N" HIY);
                msg = replace_string(msg, "$n", "$n" HIY);
                msg = HIY + msg + NOR;
                COMBAT_D->set_bhinfo(msg);
        }
}

void skill_improved(object me)
{
        int lvl;
        int layer;

        lvl = me->query_skill("qiankun-danuoyi", 1);
        layer = lvl / 50;
        if (layer > 7) layer = 7;

        if (! layer)
        {
                tell_object(me, HIM "��Ǳ������Ǭ����Ų"
                            "���ķ�����������\n" NOR);
        } else
        if ((lvl % 50) == 0)
        {
                tell_object(me, HIM "���������˵�" + chinese_number(layer) +
                            "���Ǭ����Ų���ķ���\n" NOR);
        } else
                tell_object(me, HIM "��Ե�" + chinese_number(layer) +
                            "���Ǭ����Ų���ķ��ּ�����һ���˽⡣\n" NOR);

        if (lvl > me->query_skill("force") * 2 / 3)
        {
                if (lvl < me->query_skill("force") * 2 / 3 + 10)
                {
                        tell_object(me, HIG "�������Ϣһ�����ң�����ʱ��ʱ"
                                        "�ȣ����ɵô��һ����\n����Ī������"
                                        "����ħ������Խ��Խ�Ǻ��䣬��Ϊ����"
                                        "��\n" NOR);

                        message("vision", HIG + me->name() + HIG "����ɫ����"
                                          "���̣���ò�ͣ��ֻ�ǻ����������"
                                          "��ʮ��ʹ�ࡣ\n" NOR,
                                          environment(me), ({ me }));
                        return;
                }
                tell_object(me, HIB "���Ȼ���õ�������һ���⣬��ʱ����֫"
                                "����һ���ú����ޱȣ��̲�ס����������\n" NOR);

                message("vision", HIB + me->name() + HIB "��Ȼһ������ɫ��Ȼ"
                                  "��òҰף���Ȼ������һ��������������ֹ��"
                                  "\n" NOR, environment(me), ({ me }));
        } else

        if (lvl < 350 && (lvl * 20 + 4000) > me->query("max_neili"))
        {
                if ((lvl * 20 + 4000) < me->query("max_neili") + 200)
                {
                        tell_object(me, HIR "��������ת��һ����Ϣ��һʱ������"
                              "�����ã��������ǲ�ҪóȻ������Ų���񹦡�\n" NOR);
                        return;
                }

                tell_object(me, HIR "��������ת��һ����Ϣ����Ȼ����һ����"
                      "��Ȼת����������ʱ���н�ʹ���������˼�����Ѫ��\n" NOR);
                message("vision", HIR + me->name() + HIR "��ɫ��Ȼ"
                        "һ�䣬Ż��������Ѫ����Ŀ���ġ�\n" NOR,
                        environment(me), ({ me }));
        } else
                return;

        me->apply_condition("qiankun-except", lvl +
           (int)me->query_condition("qiankun-except"));
}

void nuoyi(object ob, object me)
{
        string msg;
        int ap, dp, damage;

        if (! ob
           || ! me->is_fighting(ob)
           || ! me->query_temp("nuoyi/" + ob->query("id")))
                return;

        msg = HIM "\n$N" HIM "Ǭ����Ų�Ƶ��߲��ķ�ʩչ�������ٽ���ǰ������"
              "��ʮ��������鲢Ϊһ�ƣ���$n" HIM "���Ķ����������һ�����"
              "��ɽ�鱬��ʱ�����˺�ˮȴͻȻ��������ˮ�������һ�㡣\n" NOR;

        ap = me->query_skill("parry");
        dp = ob->query_skill("force");

        me->start_busy(2);

        if (dp / 2 + random(dp) < ap)
        {
                damage = ap + dp;
                msg += COMBAT_D->do_damage(me, ob, REMOTE_ATTACK, damage, 300,
                                           HIR "ֻ��$n" HIR "һ���ҽУ���$N"
                                           HIR "���ص��������˸�ʮ�㣬ȫ��"
                                           "�꿦��һ����죬��ǡ��۹ǡ����"
                                           "���߹Ǿ�Ȼһ���۶ϡ�\n" NOR);
        } else
        {
                msg += HIC "$n" HIC "�ۼ�$P������ӿ������"
                       "���⣬ʩ������������⿪����\n" NOR;
        }
        me->delete_temp("nuoyi");
        message_sort(msg, me, ob);
}

int practice_skill(object me)
{
        return notify_fail("Ǭ����Ų��ֻ��ͨ��ѧϰ���ж�Ǭ����Ų���ķ���ߡ�\n");
}

string perform_action_file(string func)
{
        return __DIR__"qiankun-danuoyi/" + func;
}