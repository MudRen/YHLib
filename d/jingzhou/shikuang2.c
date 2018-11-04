#include <ansi.h>
#include <room.h>
inherit ROOM;

void init()
{
        add_action("do_zha", "zha");
}

void create()
{
        set("short", "ʯ��");
        set("long", @LONG
���ｼ��һ����ɽ����ʯ��ᾣ���ɽ����һ�߲��ϴ���һ����ı�ը����ԭ
���Ѿ��кܶ������Ǳ�ը(zha)ɽ���ɿ�ʯ��
LONG );
        set("outdoors","city");
        set("exits", ([
                "northup"  : "/d/jingzhou/shikuang1",
        ]));
        set("no_fight", 1);
        set("no_sleep_room",1);
        set("no_clean_up", 0);
        setup();
}

int do_zha(string arg)
{
        object me;
        me = this_player();

        if( !present("lei guan", me))
                return notify_fail(HIY"��Ҫ��ʲô��\n"NOR);

        if( (!arg) || !((arg == "ɽ") ))
                return notify_fail(CYN"�������׹�û�¸�ѽ��\n"NOR);

        if( me->query_temp("caiend") == 1 )
                return notify_fail(HIR"�����Ѿ�����ըƽ�ˣ��������ƻ�����ѽ��\n"NOR);

        if( me->query("zha/ɽ") == 1 )
                return notify_fail(HIM"�׹��Ѿ���ȼ�ˣ��㻹Ҫ��ʲô��\n"NOR);

        if( me->is_busy()) 
                return notify_fail("����æ���أ���\n");

        if( (me->query("qi")<25) || (me->query("jing")<25) )
                return notify_fail(MAG"��̫���ˣ�׬ǮҲ������һʱ��\n"NOR);
        
        if( me->query_temp("caistone") == 1 ) {
        message_vision(HIW"$N���ֱ��ŵ����˸���϶���׹ܲ��ȥ����æ���ҵص�ȼ�˾��\n"NOR, me);
        remove_call_out("zha/ɽ");
        me->set("zha/ɽ", 1);
        call_out("bao", random(5) +5, me );
        return 1;
        }
        else {
                return notify_fail(HIY"û��������ѽ�������\n"NOR);
        }
}

int valid_leave(object me, string dir)
{
        if ( dir == "northup" && me->query_temp("zha/ɽ") == 1)
                return notify_fail(HIW"����׹ܻ����������������������\n"NOR);
        return 1;
}

void bao()
{
        object ob, me, obj, cor, cps, dex, guan;
        me = this_player();
        guan = present("lei guan", me);
        cor = me->query("cor");
        cps = me->query("cps");
        dex = me->query("dex");
        
        me->delete("zha/ɽ");
        
        if ( me->query("dex") < random(25) + 5){
        message_vision(HIR"ֻ�������䡱��һ�����죬$N�����˷��˳�ȥ��ԭ����ը��̫ǿ�ˣ����Լ���ը���ˡ�\n"NOR,me);
        me->receive_damage("qi", random(40)); 
        me->receive_damage("jing", random(40)); 
        me->start_busy(random(10) +5);
        return;
}       
        if ( me->query("cor") < random(25) + 5){
        message_vision(HIY"ֻ�������䡱��һ�����죬ȴֻ��һЩ��ʯ��������ԭ����ը��̫С�ˡ�\n"NOR,me);
        me->receive_damage("qi", random(10)); 
        me->receive_damage("jing", random(20)); 
        me->start_busy(random(5) +3);
        return;
}       
        if ( me->query("cps") < random(25) + 5){
        message_vision(BLU"$N�����۾������Ŷ�������ϰ��죬ȴʲô��û������ԭ���׹��ܳ������ˡ�\n"NOR,me);
        me->receive_damage("qi", random(10)); 
        me->receive_damage("jing", random(10)); 
        me->start_busy(random(8) +3);
        return;
}

else {
        message_vision(HIC"ֻ�������䡱��һ�����죬һ���ʯ��ɽ�Ϲ���������\n"NOR,me);
        me->delete_temp("caistone");
        me->set_temp("caiend", 1);
        destruct(guan);
        obj = new("/clone/misc/bigstone");
        obj->move(this_player());
        message_vision(MAG"$N��æ̧���ǿ��ʯ�����±������������Ͷ��ɹ�������\n"NOR, me);
        me->receive_damage("qi", random(10)); 
        me->receive_damage("jing", random(10));
        me->start_busy(random(3) +3);
     }
}
