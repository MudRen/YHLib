// inherit object: knower.c
// ��Ϣ��ͨ��ʿ�̳д˶���

#include <ansi.h>

inherit NPC;

int is_knower() { return 1; }

// ���մ�����Ϣ
mixed accept_ask(object ob, string topic)
{
        return QUEST_D->generate_information(this_object(), ob, topic);
}

void receive_damage(string type)
{
        return;
}

void receive_wound(string type)
{
        return;
}
