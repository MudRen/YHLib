#include <ansi.h> 

inherit ROOM;

void create()
{
        set("short", HIR "Ĵָ��" NOR);
        set("long", @LONG
Ĵָ���������������Ϊ�Ͱ���һ�壬��Ϊ�壬ʵ��ֻ��һ���ϸߵ�ʯ
ɽ���ˡ��嶥����ȫ���ִ���Բ����ʯ������ɹ�����£�����ʴ��ʮ��֮��
��������ʯ�ķ�϶�У������������������һ����������עĿ���ഫ�����
��Ի����������(song)����ͬ���������ھ��һ�׸ߴ�������Ϊ����������
����ͬ��ͬ�ߣ������øߴ�ͦ�Σ�֦Ҷïʢ�������ֵ�һ�㣬�������Ϊ��
���ɡ�
LONG    );
        set("exits", ([
                "southdown" : __DIR__"sslu-3",
        ]));

        set("item_desc", ([ 
                "song" : GRN "\n��������ܳ���������أ����̺����������֮������\n" NOR,
        ]));

        set("no_clean_up", 0);
        setup();
}

void init()
{
        add_action("do_caiqi", "caiqi");
}

int do_caiqi(string arg)
{
        mapping fam;
        object me;
        me = this_player();

        if ( ! living(me)) return 0;
        if ( ! living(this_player()) || arg != "song" )
        {
                message_vision("�����ʲô��\n",me);
                return 1;
        }

        if( me->is_busy() )
                return notify_fail("��������æ���ء�\n");

        if ((int)me->query_skill("force",1) > 100)
                return notify_fail("��������ڹ���Ϊ�Ѿ����޷���������ȡ�κζ����ˣ�\n");

        if ((int)me->query_skill("force", 1) < 30 )
                return notify_fail("����ڹ���Ϊ̫���ˣ�û�취�����в�����\n");

        if (! me->can_improve_skill("force"))
                return notify_fail("���ʵս���鲻�����޷��ټ�������ڹ���\n");

        if((int)me->query("jing") < 40)
        {
                write("���Ȼ���þ��񲻼ã��޷��������ڵ�������\n");
                return 1;
        }

        me->receive_damage("jing", 30);
        message_vision(HIW "$N" HIW "����˫�ۣ�˫�ֽ�������ס���ɣ���ʼ��������������\n" NOR, me);
        me->improve_skill("force", me->query("con") * 2 / 3);
        me->start_busy(random(2));
        return 1;
}
