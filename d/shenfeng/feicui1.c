#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
��������ȺɽΧ�ƣ�����һֻ����һ�㣬�������ı�ˮӨ
Ȼ��������䣬�Ǹ�Բ�εĴ�ˮ��(pool)��������ǧ���꣬��
Ȼ�������ɿݣ������ص����л�ˮԴͷ�����߽��رߣ�������
ȥֻ��������ǣ�˫������ˮ��������ˮ�ξ��峺�������˺�
̦�࣬ԭ��Բ�����ܶ�����䣬��ˮ��ӳ����ɫ��ֻ����׵�
���ӳ�ڱ��̵ĳ��У����޽ྻ���ľ������
LONG);
        set("resource/water", 1);
        set("objects", ([ 
                __DIR__"obj/skeleton3" : 1,
	]));

        set("item_desc", ([
                "pool" : HIC "\n��ˮ�ξ��峺�������˺�̦�࣬Բ�����ܶ�����䡣\n" NOR,
        ]));

        set("exits", ([ 
        	"up" : __DIR__"yongdao5",
	]));
        setup();
}

void init()
{
        add_action("do_jump", "jump");
        add_action("do_jump", "tiao");
}

int do_jump(string arg)
{
        object me = this_player();
        object cloth = me->query_temp("armor/cloth");

        if (! arg || arg == "")
                return 0;

        if (arg == "pool")
        {
                message_vision(HIC "\n$N" HIC "�������أ���Ҳ����ס�ջ���ͨһ��"
                               "������ˮ�С�\n\n" NOR, me);

                me->move(__DIR__"feicui2");

                message_vision(HIC "\n$N" HIC "��ͨһ�������������С�\n\n" NOR, me);

                if (cloth && cloth->washed(120 + random(120)))
                        tell_object(me, "�����ϵ�" + cloth->name() + "ȫʪ͸�ˡ�\n");

                return 1;
        }
}
