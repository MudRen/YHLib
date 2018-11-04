inherit SKILL;

string *dodge_msg = ({
        "$n����ڵ���һ�㣬���ΰεض��𣬶㿪����һ�С�\n",
        "ȴ����$n����һת��ͻȻת����$N�����\n",
        "$n����$N��������ʽƮ������������һƬ΢���е�����һ�㡣\n",
        "$n������һ�Ρ���һ������֪��ô�ģ��ӹ����ļ�϶�����˳�����\n",
        "$n�㲻��ص�Χ��$N����������Ȧ����$N��һ�б��˿�ȥ��\n",
        "$n����������Ȧ����������һ����Ȧ�����θ߸ߵذ���������\n",
});

int valid_enable(string usage)
{
        return usage == "dodge" || usage == "move";
}

int valid_learn(object me)
{
        if ((int)me->query_skill("dodge", 1) < 50)
                return notify_fail("������Ṧ��Ϊ���ޣ������������㹦��\n");

        if (me->query("max_neili") < 500)
                return notify_fail("��������Ϊ̫ǳ�������������㹦��\n");
        return 1;
}

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int query_effect_dodge(object attacker, object me)
{
        int lvl;

        lvl = me->query_skill("jinyan-gong", 1);
        if (lvl < 30)  return 0;
        if (lvl < 50)  return 10;
        if (lvl < 100) return 20;
        if (lvl < 150) return 30;
        if (lvl < 200) return 40;
        return 50;
}


int practice_skill(object me)
{
        if( (int)me->query("qi") < 70 )
                return notify_fail("�������̫���ˣ����������㹦��\n");

        if ((int)me->query("neili") < 60)
                return notify_fail("�������̫���ˣ����������㹦��\n");

        me->receive_damage("qi", 58);
        me->add("neili", -55);
        return 1;
}