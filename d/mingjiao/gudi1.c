#include <ansi.h>;
inherit ROOM;

void create()
{
        set("short", NOR + WHT "��ƽ̨" NOR);
        set("long", @LONG
�������������������������ǰ����һ������Ҳ�ƵĴ�ɽ
�ڣ���ǰãã�ƺ�������ȥ·���㾹��������һ������Կյļ���
ƽ̨�ϡ���ƽ̨����ʮ���ɷ�Բ�����ǰ����ٿգ��ϼȲ��ã�����
���ܣ���������·һ�������ƽ̨�ϰװ����Ķ��Ǳ�ѩ���������֣�
����Ұ�ޡ�
LONG );
        set("outdoors", "mingjiao");
        setup();
}

void init()
{
        add_action("do_climb","climb");
}

int do_climb()
{
        int n = this_player()->query_skill("dodge", 1);

        message_vision(HIY "\n$N" HIY "������һ������������"
                       "��ѩ����������\n", this_player());
        if (n > 80)
        {
                this_player()->move(__DIR__"gudi2");
                message_vision(HIR "$N" HIR "���˰��죬����"
                        "ϥ�Ƕ��ѱ���������Ѫ���죬������"
                        "��������\n\n", this_player());
        } else
        {
                message_vision(HIR "$N" HIR "����һ�ᣬһ��"
                        "С�Ļ���������ˤ��������Ѫ��\n" NOR,
                        this_player());
                this_player()->receive_damage("qi", 50);
                this_player()->receive_wound("qi", 30);
        }
        return 1;
}
