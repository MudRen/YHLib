#include <ansi.h>
inherit ROOM;
string look_map();

void create()
{
        set("short", "������");
        set("long", @LONG
�����ϻ����ײ������ܹ��߻谵����Ӱ�λΣ��ƺ��м���
�ڰ��Ķ���������ߣ�ͨ������˷���һλ����ؤ�����ֵ���
�����еĵ��ϡ�ǽ���ϻ��ŷ��ֲڵ�·��(map)��ͼ��
LONG);
        set("exits", ([
                "up"   : __DIR__"inhole",
                "west" : __DIR__"mishi",
                "east" : __DIR__"chucang",
        ]));

        set("item_desc",([
                "map"  : (: look_map :),
        ]));

        set("objects",([
                CLASS_D("gaibang") + "/liang" : 1,
                CLASS_D("gaibang") + "/jian" : 1,
                "/d/gaibang/npc/5dai" : 1,
                "/d/gaibang/npc/6dai" : 1,
                "/d/gaibang/npc/7dai" : 1,
        ]));
        setup();
        "/clone/board/gaibang_r"->foo();
}

void init()
{
        add_action("do_goto", "goto");
}

int do_goto(string arg)
{
        object midao, arrive;
        object me = this_player();
        string room, name;

        if (me->query("family/family_name") != "ؤ��")
                return notify_fail(HIR "\n�㳯�ܵ���ȥ��ͻ��һ�ɶ��"
                                   "�Ӷ��ڴ�����ʹ����æֹ����\n" NOR);

        if (! arg || arg == "")
                return notify_fail("��Ҫȥ���\n");

        switch (arg)
        {
        case "����" :
        case "fuzhou" :
                room = "/d/fuzhou/yushan";
                name = "����";
                break;

        case "����" :
        case "xiangyang" :
                room = "/d/xiangyang/xiaorong1";
                name = "����";
                break;

        case "����" :
        case "suzhou" :
                room = "/d/suzhou/chitang";
                name = "����";
                break;

        case "����" :
        case "hangzhou" :
                room = "/d/hangzhou/yuhuangshan";
                name = "����";
                break;

        case "�ɶ�" :
        case "chengdu" :
                room = "/d/city3/wuhouci";
                name = "�ɶ�";
                break;

        case "����" :
        case "jingzhou" :
                room = "/d/jingzhou/xxend";
                name = "����";
                break;

        case "����" :
        case "nanyang" :
                room = "/d/shaolin/ruzhou";
                name = "����";
                break;

        case "��ɽ" :
        case "foshan" :
                room = "/d/foshan/youtiaopu";
                name = "��ɽ";
                break;

        case "����" :
        case "dali" :
                room = "/d/dali/dahejieeast";
                name = "����";
                break;

        case "����" :
        case "hengyang" :
                room = "/d/henshan/hengyang1";
                name = "����";
                break;

        case "����" :
        case "changan" :
                room = "/d/changan/minju3";
                name = "����";
                break;

        case "����" :
        case "beijing" :
                room = "/d/beijing/minju_y";
                name = "����";
                break;

        case "����" :
        case "kaifeng" :
                room = "/d/kaifeng/jiaomen";
                name = "����";
                break;

        case "����" :
        case "zhongzhou" :
                room = "/d/zhongzhou/inpomiao";
                name = "����";
                break;

        case "����" :
        case "luoyang" :
                room = "/d/luoyang/nantou";
                name = "����";
                break;

        default:
                return notify_fail("û��ͨ���Ǹ�������ܵ���\n");
                break;
        }
        arrive = find_object(room);

        if (! arrive)
                arrive = load_object(room);

        message_vision("$N�����ʼ磬��" + name + "�ܵ�����ȥ��\n", me);

        midao = new(__DIR__"midao");
        me->move(midao);

        me->start_call_out((: call_other, __FILE__, "arrival",
                              me, midao, arrive :), 3);
        return 1;
}

void arrival(object me, object boat, object arrive)
{
        tell_object(me, HIY "\n������ڵ��ܵ��д����ţ�ͻȻ"
                        "��ǰһ����\n\n" NOR);
        me->move(arrive);
}

string look_map()
{
        return WHT "\n"
"��ؤ����ھ���ͨ���ܵ�ֱ�����³��У�\n" HIY
"����������������������������������������\n" NOR
" ����(changan)         ����(luoyang)\n"
" ����(dali)            ����(beijing)\n"
" ����(hangzhou)        ����(kaifeng)\n"
" ����(suzhou)          ����(hengyang)\n"
" ����(xiangyang)       ����(fuzhou)\n"
" �ɶ�(chengdu)         ����(jingzhou)\n"
" ����(nanyang)         ��ɽ(foshan)\n"
" ����(zhongzhou)\n" HIY
"����������������������������������������\n" NOR + WHT
"��������(" HIY "goto" NOR + WHT ")����ȴ�������ؤ����ڡ�\n" NOR;
}
