// quester.c ������������

int is_quester() { return 1; }

// ��������
int ask_quest(object who)
{
        return QUEST_D->ask_quest(this_object(), who);
}

// ȡ������
int cancel_quest(object who)
{
        return QUEST_D->cancel_quest(this_object(), who);
}
