#include <ansi.h>

string give_gift();

inherit F_CLEAN_UP;

static mixed *story = ({
        "��ʴ�ۣ��Ͼ������Ƕ���û���α�����ҩ��",
        "̫���Ͼ����У��У��������������һ���ɵ�������ʹ�˱������",
        "��ʴ�۴�ϲ�����ã���������š�",
        "̫���Ͼ��ɻ����Ī�ǡ���",
        "��ʴ�۳�̾һ�������Ǽ��ǿ�����Խ��Խ�����ˣ�����԰�����ˣ������������¹��ء�",
        "̫���Ͼ��ͳ�һ��«�����������",
        "��ʴ�ۣ���ѽ��",
        "̫���Ͼ������ã���ô���ˣ���������ȥ���ҡ�",
        "��ʴ�ۣ��������ˣ�����һ�ŵ���ٸ���һ�ž����ˡ�",
        (: give_gift :)
});

void create()
{
        seteuid(getuid());
}

mixed query_story_message(int step)
{
        return step < sizeof(story) ? story[step] : 0;
}

string give_gift()
{
        STORY_D->give_gift("/clone/fam/gift/int2", 1,
                           HIM "\n��ž����һ��һ���ɵ���������ǰ��\n\n" NOR);
        return HIM "��˵��ͥ������һö�ɵ���" NOR;
}

