// ��������ػ����̣�deliver.c

#include <ansi.h>

string *ob_list = ({
        "/clone/questob/rice",
        "/clone/questob/cloth",
        "/clone/questob/spice",
        "/clone/questob/bait",
        "/clone/questob/wood",
        "/clone/questob/metal",
        "/clone/questob/farm",
        "/clone/questob/silver",
        "/clone/questob/gold",
});

void startup();

// ������󴴽�
void create()
{
        seteuid(getuid());
        if (! clonep() && find_object(QUEST_D)) startup();
}

void start_quest()
{
        object qob;     // �������
        string name;    // Ҫ�͵Ļ���
        int amount;     // �ͻ�������

        if (sizeof(children("/clone/quest/deliver")) > 6)
                // ϵͳ����68���ͻ�������
                return;

        name = ob_list[random(sizeof(ob_list))];
        amount = 5 + random(6);

        qob = new("/clone/quest/deliver");
        qob->init_quest(name, amount);

        CHANNEL_D->do_channel(find_object(QUEST_D),
                              "sys", "����(DELIVER)����" + 
                              get_object(name)->name() +
                              HIR "������һ������");
}

private void heart_beat()
{
        if (! find_object(QUEST_D))
                return;

        // ������ԣ�ÿ����������һ��QUEST
        start_quest();
}

// �����ػ����̻����������
void startup()
{
        // ����
        if (! find_object(QUEST_D))
                return;

        if (! query_heart_beat())
                CHANNEL_D->do_channel(find_object(QUEST_D),
                                      "sys", "����(DELIVER)�����ˡ�");

        // ƽ��ÿ�ķ��Ӳ���һ������
        set_heart_beat(110 + random(20));
}

// ֹͣ����������
void stop()
{
        set_heart_beat(0);
}