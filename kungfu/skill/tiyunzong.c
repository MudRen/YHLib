inherit SKILL;

string *dodge_msg = ({
    "ֻ��$nһ�С��׺׳��졹���������ϱ�ֱ���������࣬�����$N��һ�С�\n",
    "$nһ�������ӷ���������ݳ�����֮Զ���ܿ���$N���������ơ�\n",
    "$nʹ��������չ�᡹����һ��ƮȻ�ݳ��������ŵء�\n"
    "����$n����Ʈ��������һ�ݣ����ѱܿ���\n",
    "$n������ת��ٿ����һ��Ų�������ߣ��ܹ�����һ�С�\n",
    "����$n����һ�ã�$N��һ�����˸��ա�\n",
    "ȴ��$n�㲻��أ����Դܿ����ߣ����˿�ȥ��\n",
    "$n����΢�Σ��о����յرܿ���$N��һ�С�\n"
});

int valid_enable(string usage)
{
        return (usage == "dodge" || usage == "move");
}

int valid_learn(object me)
{
        if ((int)me->query_skill("dodge", 1) < 80)
                return notify_fail("������Ṧ��Ϊ���ޣ��������������ݡ�\n");

        if (me->query("max_neili") < 800)
                return notify_fail("��������Ϊ̫ǳ���������������ݡ�\n");
        return 1;
}

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int query_effect_dodge(object attacker, object me)
{
        int lvl;

        lvl = me->query_skill("tiyunzong", 1);
        if (lvl < 50)  return 0;
        if (lvl < 100) return 20;
        if (lvl < 150) return 30;
        if (lvl < 200) return 50;
        if (lvl < 250) return 70;
        return 80;
}

int practice_skill(object me)
{
        if( (int)me->query("qi") < 70 )
                return notify_fail("�������̫���ˣ������������ݡ�\n");

        if ((int)me->query("neili") < 60)
                return notify_fail("�������̫���ˣ�������ϰ�����ݡ�\n");

        me->receive_damage("qi", 58);
        me->add("neili", -55);
        return 1;
}
